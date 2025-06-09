#ifndef SOUND_CLASS_H
#define SOUND_CLASS_H

#include <AL/al.h>
#include <AL/alc.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>

class SoundProgram
{
public:

	static ALCdevice* device;
	static ALCcontext* context;

	bool isPlay = false;

	void playSound(float Volume);

	void SetVolume(float Volume);
	
	void SetSoundPosition(float x, float y, float z);

	void SetListenerPosition(float x, float y, float z);

	void StopSound();

	void CreateSound(std::string Path);

	void ChangeSound(std::string path);

	void DeleteSound();

private:

	ALuint buffer;
	ALuint source;
	ALint state;

	bool loadWavFile(const std::string& filename, ALuint* buffer);

};

#endif //SOUND_CLASS_H