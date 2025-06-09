#include "executeClass.h"

void Execute::file(std::string programPath) {

    std::string command = "start \"\" \"" + programPath + "\""; // Using 'start' for non-blocking GUI app

    //std::cout << "\nExecuting command: " << command << std::endl;

    system(command.c_str());
    // this segmant here runs "the command string"
    //int result = system(command.c_str());

    //if (result == 0) {
    //    std::cout << "External program launched successfully with administrator privileges." << std::endl;
    //}
    //else {
    //    std::cerr << "Failed to launch external program. Error code: " << result << std::endl;
     //   std::cerr << "Please ensure the path is correct and the program exists." << std::endl;
    //}
}

void Execute::fileElevated(const std::string& programPath) {
    std::wstring wideProgramPath(programPath.begin(), programPath.end()); // Convert to wstring

    SHELLEXECUTEINFOW sei = { sizeof(sei) };
    sei.lpVerb = L"runas"; // Request elevation
    sei.lpFile = wideProgramPath.c_str(); // Path to the executable
    sei.lpParameters = NULL; // exe parameters if needed
    sei.lpDirectory = NULL; // Current directory (optional)
    sei.nShow = SW_SHOWNORMAL; // Show the window normally
    // sei.fMask = SEE_MASK_FLAG_NO_UI; suppress UAC prompt on failure

     //exectute the program with administrator privileges
    ShellExecuteEx(&sei);
    /*
    if (!ShellExecuteEx(&sei)) {
        DWORD dwError = GetLastError();
        std::cerr << "Failed to launch program as administrator. Error code: " << dwError << std::endl;

        if (dwError == ERROR_CANCELLED) {
            std::cout << "User cancelled the UAC prompt." << std::endl;
        }
        else if (dwError == ERROR_FILE_NOT_FOUND) {
            std::cerr << "Error: The specified file was not found. Check the path." << std::endl;
        }
        else {
            std::cerr << "An unexpected error occurred." << std::endl;
        }
    }
    else {
        std::cout << "UAC prompt should have appeared. If accepted, Notepad.exe should be running with administrator privileges." << std::endl;
    }
    */

}

void Execute::command(const std::string& command) {
 system((command.c_str()));
   // "ipconfig /all"
 //std::cout << "\nRunning an admin-level command-line tool..." << std::endl;
// int adminCommandResult = system("ipconfig /all");
// if (adminCommandResult == 0) {
//     std::cout << "Admin command executed successfully." << std::endl;
// }
// else {
//     std::cerr << "Admin command failed. Error code: " << adminCommandResult << std::endl;
// }

// std::cout << "\nProgram finished." << std::endl;
 //system("pause"); // pause the console until user input
}