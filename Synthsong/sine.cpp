#include <iostream>
#include "sine.h"
#include "math.h"

Sine::Sine() : Oscillator()
{
  std::cout << "Sine - constructor\n";
}


Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}


float Sine::sineOut(float amplitude, float frequency) {
  phase += frequency / samplerate;
  sample = amplitude * sin(M_PI * 2 * phase);
  return sample;
}
