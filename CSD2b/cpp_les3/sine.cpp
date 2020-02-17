#include "sine.h"

Sine::Sine(float freq)
{
  //initialize members
  this->freq = freq;
  amp = 1.0:
  sample = 0;
  phase = 0;
  std::cout()
}

float Sine::getSample()
{
  return sample;
}

void  Sine::tick()
{
  phase += freq / SAMPLERATE; //TODO implement in a more efficent way
  sample = sin(TWO_PI * phase);
}

//getters and setters
void Sine::setFreq
