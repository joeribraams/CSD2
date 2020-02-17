#include <iostream>
#include "sine.h"
#include "math.h"

Sine::Sine(){}

Sine::~Sine() {}

//calculates and outputs sine wave
float Sine::sineOut(float amplitude, float frequency)
{
  phase += frequency / 44100;
  sample = amplitude * sin(M_PI * 2 * phase);
  return sample;
}
