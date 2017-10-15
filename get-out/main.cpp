#include "Application.h"
#include "globals.h"

int main()
{
	LoopStatus loopStatus = LoopStatus::CONTINUE;

	// Start-up Application
	OutputLog("INFO: App will initiate.");
	Application app;
	loopStatus = app.init();

	OutputLog("INFO: App will update.");
	while (loopStatus == LoopStatus::CONTINUE)
	{
		loopStatus = app.update();
	}

	// Close-up Application
	if (loopStatus == LoopStatus::EXIT)
	{
		OutputLog("INFO: User requested App closure.");
		OutputLog("INFO: App will close.");
		loopStatus = app.close();
	}

	switch (loopStatus)
	{
	case LoopStatus::INIT_ERROR:
		OutputLog("ERROR: App failed at initiation!");
		break;
	case LoopStatus::UPDATE_ERROR:
		OutputLog("ERROR: App failed during update!");
		break;
	case LoopStatus::CLOSE_ERROR:
		OutputLog("ERROR: App failed at closure!");
		break;
	case LoopStatus::CONTINUE:
		// We shouldn't hit this point if loopStatus is Continue
		OutputLog("ERROR: Main looped aborted!");
		break;
	case LoopStatus::EXIT:
		OutputLog("INFO: App exited successfully!");
		break;
	default:
		break;
	}

	return 0;
}

// TODO: FIX BUG: Ctrl+C crashes app