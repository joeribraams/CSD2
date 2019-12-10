#include <iostream>
#include <string>
#include "Synth.h"

//Constructor also prints instrument range
Synth::Synth() : Instrument()
{
  std::cout << "Synth - Constructor, range is: " << rangeLow << "," << rangeHigh << std::endl;
  sound = "Bliep";
}

//Destructor
Synth::~Synth()
{
  std::cout << "Synth - Destructor\n";
}
