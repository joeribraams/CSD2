#include <iostream>
#include <string>
#include "Synth.h"

//Constructor also prints instrument range
Synth::Synth()
{
  std::cout << "Synth - Constructor, range is: " << rangeLow << "," << rangeHigh << std::endl;
}

//Destructor
Synth::~Synth()
{
  std::cout << "Synth - Destructor\n";
}

//Prints noise for playTimes amount
void Synth::play(int playTimes)
{
  for( int i = 0; i < playTimes; i = i + 1 )
  {
    std::cout << "Bliep" << std::endl;
  }
}
