#include "Audiomanager.hpp"


AudioManager::AudioManager()
    : _backgroundMusic()
{
    InitAudioDevice();  
    _backgroundMusic = LoadSound("../assets/sounds/music.mp3");
}

AudioManager::~AudioManager()
{
    StopSound(_backgroundMusic);
    UnloadSound(_backgroundMusic);
    CloseAudioDevice(); 
}


bool AudioManager::IsMusicplaying() const {
    return IsSoundPlaying(_backgroundMusic);
}


void AudioManager::PlayMusic()
{
    PlaySound(_backgroundMusic);
    SetSoundVolume(_backgroundMusic, 0.3f); // Réduit le volume à 50%
}

void AudioManager::StopMusic()
{
    StopSound(_backgroundMusic);
}

