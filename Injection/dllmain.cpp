#include "stdafx.h"
#include <iostream>

DWORD WINAPI threadFunction(LPVOID lpParam){
	for (int i = 0; i < 10; i++) {
		std::cout << "From injected dll " << i << "\n";
		Sleep(1000);
	}
	return 0;
}

void createThread() {
	HANDLE threadHandle = CreateThread(
	nullptr,                   // default security attributes
	0,                      // use default stack size  
	threadFunction,			// thread function name
	nullptr,					// argument to thread function 
	0,                      // use default creation flags 
	nullptr);   // returns the thread identifier 


	// Check the return value for success.
	// If CreateThread fails, terminate execution. 
	// This will automatically clean up threads and memory. 
	if (threadHandle == NULL)
	{

	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		std::cout << "DLL_PROCESS_ATTACH\n";
		createThread();
		break;
    case DLL_THREAD_ATTACH:
		std::cout << "DLL_THREAD_ATTACH\n";
		break;
    case DLL_THREAD_DETACH:
		std::cout << "DLL_THREAD_DETACH\n";
		break;
    case DLL_PROCESS_DETACH:
		std::cout << "DLL_PROCESS_DETACH\n";
		break;
    }
    return TRUE;
}

