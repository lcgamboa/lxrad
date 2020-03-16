
#ifndef LXAUDIO_H
#define LXAUDIO_H


void lxaudio_Init (void);
void lxaudio_End (void);

unsigned int lxaudio_GetSampleRate (void);
unsigned int lxaudio_GetMax(void);

void lxaudio_BeepStart (float freq = 440, float volume = 1.0);
void lxaudio_BeepStop (void);

void lxaudio_SoundPlay (short * samples, size_t buf_size);
int lxaudio_SoundProcess (void);

#endif /* LXAUDIO_H */

