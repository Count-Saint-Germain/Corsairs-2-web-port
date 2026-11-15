bool exitBool = true;

void InitInterface(string iniName)
{
    Trace("SELECT_TRACE init");
    GameInterface.title = "titleSelect";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);
}

void ProcessCancelExit()
{
    Trace("SELECT_TRACE cancel");
	IDoExit( RC_INTERFACE_SELECTMENU_EXIT );
}

void IDoExit(int exitCode)
{
    Trace("SELECT_TRACE exit " + exitCode);
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("evntDoPostExit","DoPostExit");

	interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true ) {
		exitBool = true;
	}
	if(exitBool)	DeleteAttribute(&InterfaceStack,"SelectMenu_node");
	EndCancelInterface(exitBool);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
    Trace("SELECT_TRACE command " + comName + " node " + nodName);

	if(comName=="activate" || comName=="click")
	{
		PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SELECTMENU_EXIT);
		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
	}
}

void DoPostExit()
{
	int exitCode = GetEventData();
    Trace("SELECT_TRACE delayed exit fired");
	exitBool = false;
	IDoExit(exitCode);
}
