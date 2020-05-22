
#ifndef LXAUDIO_H
#define LXAUDIO_H

#include <AL/al.h> 

#define MAXBUFF 8

class lxaudio {
private:
    ALuint buf[MAXBUFF];
    ALuint src;
    short * int_samples;
    size_t int_buf_size;
    int bcount; 
public:
    static int open;
    void Init(int bcount_ = 1);
    void End(void);

    unsigned int GetSampleRate(void);
    unsigned int GetMax(void);

    void BeepStart(float freq = 440, float volume = 1.0);
    void BeepStop(void);

    void SoundPlay(short * samples, size_t buf_size);
    int SoundProcess(void);
};


#endif /* LXAUDIO_H */

