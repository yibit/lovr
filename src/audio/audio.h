#include "audio/source.h"
#include "lib/vec/vec.h"
#include <AL/al.h>
#include <AL/alc.h>
#ifndef EMSCRIPTEN
#include <AL/alext.h>
#endif

#pragma once

typedef struct {
  ALCdevice* device;
  ALCcontext* context;
  vec_void_t sources;
  int isSpatialized;
  float orientation[4];
  float position[3];
  float velocity[4];
} AudioState;

void lovrAudioInit();
void lovrAudioDestroy();
void lovrAudioUpdate();
void lovrAudioAdd(Source* source);
void lovrAudioGetOrientation(float* angle, float* ax, float* ay, float* az);
void lovrAudioGetPosition(float* x, float* y, float* z);
void lovrAudioGetVelocity(float* x, float* y, float* z);
float lovrAudioGetVolume();
int lovrAudioHas(Source* source);
int lovrAudioIsSpatialized();
void lovrAudioPause();
void lovrAudioResume();
void lovrAudioRewind();
void lovrAudioSetOrientation(float angle, float ax, float ay, float az);
void lovrAudioSetPosition(float x, float y, float z);
void lovrAudioSetVelocity(float x, float y, float z);
void lovrAudioSetVolume(float volume);
void lovrAudioStop();
