#include <iostream>
#include "saw.h"
#include "math.h"

Saw::Saw() : Oscillator()
{
  std::cout << "Saw - constructor\n";
}


Saw::~Saw() {
  std::cout << "Saw - destructor\n";
}


float Saw::sawOut(float amplitude, float frequency) {
  phase += frequency / 44100;
  if(phase >= 2) {
    phase = 0;
  }
  sample = amplitude * (phase - 1);
  return sample;
}
