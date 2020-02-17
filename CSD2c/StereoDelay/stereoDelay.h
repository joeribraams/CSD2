#pragma once
#include "circBuffer.h"
#include "sine.h"
#include <iostream>

class stereoDelay
{
public:
  // initializes the circ buffers for both channels
  CircBuffer buff1;
  CircBuffer buff2;
  // initializes a sine for delaytime modulation
  Sine sine1;
  // Constructor and destructor
  stereoDelay(float sampleRate, float delayTime, float feedback, float wet, float dry);
  ~stereoDelay();
  // write sample to the buffers
  void write(float inSample);
  // output the output samples and dry signal
  inline float readLeft() {return (outSampleL * wetLevel) + (inSample * dryLevel);}
  inline float readRight() {return (outSampleR * wetLevel) + (inSample * dryLevel);}
  // set settings
  inline void setTime(float delayTime) {this->delaySize = 441000 /(sampleRate * (delayTime/1000));}
  inline void setSamplerate(float sampleRate) {this->sampleRate = sampleRate;}
  inline void setFeedback(float feedback) {this->feedback = feedback;}
  inline void setWetLevel(float wet) {this->wetLevel = wet;}
  inline void setDryLevel(float dry) {this->dryLevel = dry;}

protected:
  int sampleRate;
  float delaySize;
  // for time smoothing and delay modulation
  float modTime;
  float oldTime;
  float newTime;
  // settings

  float feedback;
  float wetLevel;
  float dryLevel;
  // storage of samples
  float inSample;
  float outSampleL;
  float outSampleR;
  float lastSampleL;
  float lastSampleR;
};
