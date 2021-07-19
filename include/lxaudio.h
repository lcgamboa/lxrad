
#ifndef LXAUDIO_H
#define LXAUDIO_H

#include <AL/al.h> 

#define MAXBUFF 8

class lxaudio {
private:
    int bstatus[MAXBUFF];
    ALuint buf[MAXBUFF];
    ALuint src;
    int bcount; 
    void CleanBuffers(void);
    int GetFreeBuffer(void);
public:
    static int open;
    void Init(int bcount_ = 4);
    void End(void);

    unsigned int GetSampleRate(void);
    unsigned int GetMax(void);

    void BeepStart(float freq = 440, float volume = 1.0, int type = 0);
    void BeepStop(void);
  
    int IsPlaying(void);
    int SoundPlay(short * samples, size_t buf_size);
};


#endif /* LXAUDIO_H */

