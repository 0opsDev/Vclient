#include <iostream>
#include "local/executeClass.h"
#include "local/packer.h"
#include "audio/SoundProgram.h"
#include "audio/SoundRunner.h"
#include "Main.h"

bool MainClass::sleepState = false; // Initialize sleep state to false

void CloseConsoleWindow() {
    HWND hwnd = GetConsoleWindow();
    if (hwnd != nullptr) {
        FreeConsole();
        PostMessage(hwnd, WM_CLOSE, 0, 0);
    }
}

void init() {
    //std::ios::sync_with_stdio(false); // Disable synchronization with C-style I/O for performance
    //std::cin.tie(nullptr); // Untie cin from cout for performance
    CloseConsoleWindow(); // Close the console window if it exists
    MainClass::sleepState = true;
    SoundRunner::init(); // Initialize OpenAL
}

int main() {
    init();
    size_t dataSize = 0;
    unsigned char* data = packer::read("simple hello world.exe", dataSize);
    if (data == nullptr) {
    //    std::cerr << "Read failed\n";
    }
    else {
        packer::write("simple hello world copy.exe", data, dataSize);
        delete[] data;
    }

	// execution
	Execute::file("C:\\Windows\\System32\\calc.exe"); // if Vclient already has admin this will do fine
	//Execute::fileElevated("C:\\Windows\\System32\\calc.exe"); // requires admin to run Vclient.exe (popup)
	//Execute::command("ipconfig /all");

    // sound device creation
    SoundProgram SPro; // create audio device
    SPro.CreateSound("Clair de Lune.wav"); // load sound file
    SPro.SetListenerPosition(0, 0, 0);
    SPro.SetSoundPosition(0, 0, 0);
    //
    while (true) { // while loop (keep program running)
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // simulate ~60 FPS (so audio doesnt play at insane speeds)

        //playing sound
        if (!SPro.isPlay) { // if sound isnt playing, play sound
            SPro.playSound(1);
        }
    }

    // Clean up
    MainClass::sleepState = false;
    SPro.DeleteSound(); // you do not needed this, but its nice to have
	SoundRunner::Delete(); // close OpenAL device and context
    return 0;
}