#include "stereoDelay.h"
#include "circBuffer.h"
#include "sine.h"
#include <math.h>

stereoDelay::stereoDelay(float sampleRate, float delayTime, float feedback, float wet, float dry)
{
  // sets size and allocates buffers
  buff1.resetSize(441000);
  buff1.allocateBuffer();
  buff1.setDistanceRW(440999);
  buff2.resetSize(441000);
  buff2.allocateBuffer();
  buff2.setDistanceRW(440999);
  // sets settings
  setSamplerate(sampleRate);
  setTime(delayTime);
  setFeedback(feedback);
  setWetLevel(wet);
  setDryLevel(dry);
}

stereoDelay::~stereoDelay(){}

void stereoDelay::write(float inSample)
{
  // smoothing of delay times and adding sine for modulation
  newTime = 0.9999 * oldTime + 0.0001 * delaySize;
  oldTime = newTime;
  modTime = newTime + sine1.sineOut(1, 0.2);

  // we write an amount of samples per sample, to change pitch with delay time
  for(int i = 0; i < modTime; i++)
  {
    // writes input and feedback with some saturation to circ buffer
    buff1.write(tanh(inSample + outSampleR * feedback));
    buff1.incrWriteH();

    buff2.write(tanh(outSampleL * feedback));
    buff2.incrWriteH();

    // reads the outputs with some saturation and low pass
    outSampleL = atan(buff1.read()/2 + lastSampleL/2);
    buff1.incrReadH();

    outSampleR = atan(buff2.read()/2 + lastSampleR/2);
    buff2.incrReadH();
  }
  // saves the last samples for low pass filters
  lastSampleL = outSampleL;
  lastSampleR = outSampleR;
}
