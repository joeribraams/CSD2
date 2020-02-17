#pragma once
#include "circBuffer.h"
#include "sine.h"
#include <iostream>

class Delay
{
public:
  CircBuffer buff1;
  Sine sine1;
  //Constructor and destructor
  Delay(float sampleRate, float delayTime, float feedback, float wet, float dry);
  ~Delay();

  //write sample
  float readWrite(float inSample);

  inline void setTime(float delayTime) {this->delaySize = 441000 /(sampleRate * (delayTime/1000));}
  inline void setSamplerate(float sampleRate) {this->sampleRate = sampleRate;}
  inline void setFeedback(float feedback) {this->feedback = feedback;}
  inline void setWetLevel(float wet) {this->wetLevel = wet;}
  inline void setDryLevel(float dry) {this->dryLevel = dry;}
  void setSamples();

protected:
  int sampleRate;
  float delaySize;
  float modTime;
  float feedback;
  float wetLevel;
  float dryLevel;

  float inSample;
  float outSample;
  float lastSample;
};
