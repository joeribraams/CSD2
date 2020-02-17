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

private:

  float sample; // contains the current sample
};
