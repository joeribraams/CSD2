#include <iostream>
#include "addsynth.h"

addSynth::addSynth()
{
  std::cout << "AddSynth - constructor\n";
}


addSynth::~addSynth()
{
  std::cout << "AddSynth - destructor\n";
}

Sine sine1;
Sine sine2;
Sine sine3;
Sine sine4;
Sine sine5;

float addSynth::addSynthOut(float frequency) {
  output = saw1.sawOut(0.5, frequency) + saw2.sawOut(0.5, (1.01*frequency));
  return output;
}
