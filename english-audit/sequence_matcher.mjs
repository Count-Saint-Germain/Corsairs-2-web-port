/** difflib-compatible sequence matching for localization audits. */
export class SequenceMatcher {
  constructor(a,b,{autojunk=true}={}){
    this.a=typeof a==='string'?[...a]:a;this.b=typeof b==='string'?[...b]:b;this.b2j=new Map();
    for(let i=0;i<this.b.length;i++){const value=this.b[i];if(!this.b2j.has(value))this.b2j.set(value,[]);this.b2j.get(value).push(i);}
    if(autojunk&&this.b.length>=200){const limit=Math.floor(this.b.length/100)+1;for(const [value,indices] of this.b2j)if(indices.length>limit)this.b2j.delete(value);}
  }
  findLongestMatch(alo,ahi,blo,bhi){let bestI=alo,bestJ=blo,bestSize=0,j2len=new Map();
    for(let i=alo;i<ahi;i++){const next=new Map();for(const j of this.b2j.get(this.a[i])||[]){if(j<blo)continue;if(j>=bhi)break;const k=(j2len.get(j-1)||0)+1;next.set(j,k);if(k>bestSize){bestI=i-k+1;bestJ=j-k+1;bestSize=k;}}j2len=next;}
    while(bestI>alo&&bestJ>blo&&this.a[bestI-1]===this.b[bestJ-1]){bestI--;bestJ--;bestSize++;}
    while(bestI+bestSize<ahi&&bestJ+bestSize<bhi&&this.a[bestI+bestSize]===this.b[bestJ+bestSize])bestSize++;
    return [bestI,bestJ,bestSize];
  }
  matchingBlocks(){if(this._blocks)return this._blocks;const matches=[],queue=[[0,this.a.length,0,this.b.length]];
    while(queue.length){const [alo,ahi,blo,bhi]=queue.pop(),[i,j,n]=this.findLongestMatch(alo,ahi,blo,bhi);if(n){matches.push([i,j,n]);if(alo<i&&blo<j)queue.push([alo,i,blo,j]);if(i+n<ahi&&j+n<bhi)queue.push([i+n,ahi,j+n,bhi]);}}
    matches.sort((x,y)=>x[0]-y[0]||x[1]-y[1]);const compact=[];let i1=0,j1=0,n1=0;
    for(const [i,j,n] of matches){if(i1+n1===i&&j1+n1===j)n1+=n;else{if(n1)compact.push([i1,j1,n1]);i1=i;j1=j;n1=n;}}
    if(n1)compact.push([i1,j1,n1]);compact.push([this.a.length,this.b.length,0]);return this._blocks=compact;
  }
  opcodes(){const codes=[];let i=0,j=0;for(const [ai,bj,n] of this.matchingBlocks()){let tag='';if(i<ai&&j<bj)tag='replace';else if(i<ai)tag='delete';else if(j<bj)tag='insert';if(tag)codes.push([tag,i,ai,j,bj]);if(n)codes.push(['equal',ai,ai+n,bj,bj+n]);i=ai+n;j=bj+n;}return codes;}
  ratio(){const sum=this.matchingBlocks().reduce((n,x)=>n+x[2],0),total=this.a.length+this.b.length;return total?2*sum/total:1;}
}
