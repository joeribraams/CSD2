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

//inits oscillators and lfo
Sine sine1;
Sine sine2;
Sine sine3;
Sine sine4;
Sine sine5;
Saw envelope;

//adds partials and multiplies them by a saw wave used as an lfo
float addSynth::addSynthOut(float frequency) {
  output = (sine1.sineOut(0.37, (1 * frequency)) +
            sine2.sineOut(0.67, (1.64 * frequency)) +
            sine3.sineOut(1, (2.12 * frequency)) +
            sine4.sineOut(0.62, (3.04 * frequency)) +
            sine5.sineOut(0.54, (4.89 * frequency)) ) *
            ((envelope.sawOut(0.5, 1)-0.5)/2);
  return output;
}
