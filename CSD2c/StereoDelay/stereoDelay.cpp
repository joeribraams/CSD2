#include "stereoDelay.h"
#include "circBuffer.h"
#include "sine.h"
#include <math.h>

stereoDelay::stereoDelay(float sampleRate, float delayTime, float feedback, float wet, float dry)
{
  buff1.resetSize(441000);
  buff1.allocateBuffer();
  buff1.setDistanceRW(440999);
  buff2.resetSize(441000);
  buff2.allocateBuffer();
  buff2.setDistanceRW(440999);
  setSamplerate(sampleRate);
  setTime(delayTime);
  setFeedback(feedback);
  setWetLevel(wet);
  setDryLevel(dry);
}

stereoDelay::~stereoDelay(){}

void stereoDelay::write(float inSample)
{
  newTime = 0.999 * oldTime + 0.001 * delaySize;
  oldTime = newTime;
  modTime = newTime + sine1.sineOut(1, 0.2);

  for(int i = 0; i < modTime; i++)
  {
    buff1.write(tanh(inSample + outSampleR * feedback));
    buff1.incrWriteH();

    buff2.write(tanh(outSampleL * feedback));
    buff2.incrWriteH();

    outSampleL = atan(buff1.read()/2 + lastSampleL/2);
    buff1.incrReadH();

    outSampleR = atan(buff2.read()/2 + lastSampleR/2);
    buff2.incrReadH();
  }

  lastSampleL = outSampleL;
  lastSampleR = outSampleR;
}
