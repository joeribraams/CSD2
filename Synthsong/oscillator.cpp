#include <iostream>
#include "oscillator.h"

Oscillator::Oscillator()
{
  std::cout << "Oscillator - constructor\n";
}


Oscillator::~Oscillator()
{
  std::cout << "Oscillator - destructor\n";
}

//resets the phase
void Oscillator::phaseReset()
{
  phase = 0;
}
