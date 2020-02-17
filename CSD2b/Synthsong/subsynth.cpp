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

//inits the oscilators
Saw saw1;
Saw saw2;
Saw saw3;

//adds and outputs the saws together with slight detune
float subSynth::subSynthOut(float frequency) {
  output = saw1.sawOut(0.3, frequency) + saw2.sawOut(0.3, (1.01*frequency)) + saw3.sawOut(0.3, (0.993*frequency));
  return output;
}
