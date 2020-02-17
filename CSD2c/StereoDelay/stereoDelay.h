#pragma once
#include "circBuffer.h"
#include "sine.h"
#include <iostream>

class stereoDelay
{
public:
  CircBuffer buff1;
  CircBuffer buff2;
  Sine sine1;
  //Constructor and destructor
  stereoDelay(float sampleRate, float delayTime, float feedback, float wet, float dry);
  ~stereoDelay();

  //write sample
  void write(float inSample);
  inline float readLeft() {return outSampleL * wetLevel + inSample * dryLevel;}
  inline float readRight() {return outSampleR * wetLevel + inSample * dryLevel;}

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
  float oldTime;
  float newTime;

  float feedback;
  float wetLevel;
  float dryLevel;

  float inSample;
  float outSampleL;
  float outSampleR;
  float lastSampleL;
  float lastSampleR;
};
