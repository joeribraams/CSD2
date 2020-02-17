#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "math.h"

#define TWO_PI 6.2831853071959
#define SAMPLERATE 44100

class Sine
{
public:
  //Constructor and destructor
  Sine(float freq);
  ~Sine();

  float getSample(); //return current sample
  void tick(); //goto next sample

  //setters and getters
  void setFreq(float freq);
  float getFreq();

private:
  float amp;
  float freq;
  float phase;
  float sample; //contains current sample
};

#endif
