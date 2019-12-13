#include <iostream>
#include "subsynth.h"

subSynth::subSynth()
{
  std::cout << "SubSynth - constructor\n";
}


subSynth::~subSynth()
{
  std::cout << "SubSynth - destructor\n";
}

Saw saw1;
Saw saw2;

float subSynth::subSynthOut(float frequency) {
  output = saw1.sawOut(0.5, frequency) + saw2.sawOut(0.5, (1.01*frequency));
  return output;
}
