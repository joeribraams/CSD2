#pragma once
#include "oscillator.h"

class Saw : public Oscillator
{
public:
  //Constructor and destructor
  Saw();
  ~Saw();

  //return sample
  float sawOut(float amplitude, float frequency);

  void sawReset();

private:
  float phase; // contains the current phase, sorta misused for the saw wave
  float sample; // contains the current sample
};
