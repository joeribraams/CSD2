#include "delay.h"
#include "circBuffer.h"
#include "sine.h"
#include <math.h>

Delay::Delay(float sampleRate, float delayTime, float feedback, float wet, float dry)
{
  buff1.resetSize(441000);
  buff1.allocateBuffer();
  buff1.setDistanceRW(440999);
  setSamplerate(sampleRate);
  setTime(delayTime);
  setFeedback(feedback);
  setWetLevel(wet);
  setDryLevel(dry);
}


Delay::~Delay(){}


float Delay::readWrite(float inSample)
{
  modTime = delaySize + sine1.sineOut(1, 0.2);
  for(int i = 0; i < modTime; i++)
  {
    buff1.write(tanh(inSample + outSample * feedback));
    buff1.incrWriteH();

    outSample = tanh(buff1.read()/2 + lastSample/2);
    buff1.incrReadH();
  }

  lastSample = outSample;
  return outSample * wetLevel + inSample * dryLevel;
}
