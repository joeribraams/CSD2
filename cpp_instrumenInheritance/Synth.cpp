#include <iostream>
#include <string>
#include "Synth.h"

Synth::Synth()
{
  std::cout << "Synth - Constructor, range is: " << rangeLow << "," << rangeHigh << std::endl;
}

Synth::~Synth()
{
  std::cout << "Synth - Destructor\n";
}

void Synth::play(int playTimes)
{
  for( int i = 0; i < playTimes; i = i + 1 )
  {
    std::cout << "Bliep" << std::endl;
  }
}
