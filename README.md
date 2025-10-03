no idea what this is about, i think i just wanted to make an installer for farquhar engine or something, and got side tracked and made some 'shitpost' program that builds itself plays audio,
anyways includes basic functions to execute things, and read things to and from binary

Documentation
---
**READ AND WRITE**

#include "local/packer.h"

---
Read File into binary:
~~~
size_t dataSize = 0;
unsigned char* data = packer::read("simple hello world.exe", dataSize);

delete[] data;
~~~
---
Create file from binary:
~~~
packer::write("simple hello world copy.exe", data, dataSize);
or if data[] rather than data*
packer::write("simple hello world copy.exe", data, sizeof(data));

~~~
---
**EXECUTION**

#include "local/executeClass.h"

---
file
~~~
Execute::file("C:\\Windows\\System32\\calc.exe"); // if Vclient already has admin this will do fine
~~~
---
fileElevated
~~~
Execute::fileElevated("C:\\Windows\\System32\\calc.exe"); // requires admin to run Vclient.exe (popup)
~~~
---
command
~~~
Execute::command("ipconfig /all");
~~~
---
**Sound**
---
#include "audio/SoundProgram.h"

#include "audio/SoundRunner.h"

---
create sound object
~~~
    SoundProgram SProj; // create audio device
    SProj.CreateSound("Clair de Lune.wav"); // load sound file
    SProj.SetListenerPosition(0, 0, 0); //
    SProj.SetSoundPosition(0, 0, 0);
~~~
---
playing sound
~~~
SPro.playSound(1); // (1 is volume)
also a bool SPro.isPlay

you should place playsound in a while or for loop and also do something like
"std::this_thread::sleep_for(std::chrono::milliseconds(16));" to limit the
sound to 60hz, so it doesnt bug out

example:
    while (true) { // while loop (keep program running)
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // simulate ~60 FPS (so audio doesnt play at insane speeds)

        //playing sound
        if (!SPro.isPlay) { // if sound isnt playing, play sound
            SPro.playSound(1);
        }
    }
~~~
