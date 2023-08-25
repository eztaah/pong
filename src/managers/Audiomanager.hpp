#include <raylib.hpp>

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    bool IsMusicplaying() const;

    void PlayMusic();
    void StopMusic();

private:
    Sound _backgroundMusic;
};