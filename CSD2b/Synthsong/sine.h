#pragma once
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine();
  ~Sine();

  //return sample
  float sineOut(float amplitude, float frequency);

private:
  float phase;  // contains the current phase
  float sample; // contains the current sample
};
