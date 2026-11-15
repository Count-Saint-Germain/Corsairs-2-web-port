import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Program;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.LinkedHashMap;
import java.util.Map;

public class DumpStringXrefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outPath = args.length > 0 ? args[0] : "/tmp/dump.txt";
        String needle = args.length > 1 ? args[1] : "LaunchIAfterFrame";
        PrintWriter out = new PrintWriter(new FileWriter(outPath));
        DecompInterface di = new DecompInterface();
        di.setOptions(new DecompileOptions());
        di.openProgram(currentProgram);

        Map<Function, Address> hit = new LinkedHashMap<>();
        Address foundAt = null;
        for (Data d : currentProgram.getListing().getDefinedData(true)) {
            Object val = d.getValue();
            String v = (val instanceof String) ? (String) val : null;
            if (v != null && v.contains(needle)) {
                out.println("// STRING " + d.getAddress() + " : " + v);
                if (foundAt == null) foundAt = d.getAddress();
                ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(d.getAddress());
                while (it.hasNext()) {
                    Reference r = it.next();
                    Function f = getFunctionContaining(r.getFromAddress());
                    if (f == null) {
                        out.println("  ref from " + r.getFromAddress() + " (no function)");
                        continue;
                    }
                    out.println("  ref from " + r.getFromAddress() + " in " + f.getName() + " @ " + f.getEntryPoint());
                    hit.putIfAbsent(f, r.getFromAddress());
                }
            }
        }
        for (Function f : hit.keySet()) {
            out.println();
            out.println("// ===== FUNCTION " + f.getName() + " @ " + f.getEntryPoint() + " =====");
            DecompileResults res = di.decompileFunction(f, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                out.println(res.getDecompiledFunction().getC());
            } else {
                out.println("// decompile failed: " + (res == null ? "null" : res.getErrorMessage()));
            }
        }
        if (hit.isEmpty()) out.println("// NO REFERENCES FOUND to strings containing: " + needle);
        out.close();
        di.dispose();
        println("DumpStringXrefs wrote " + outPath + " (" + hit.size() + " functions)");
    }
}
