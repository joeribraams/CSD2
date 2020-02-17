#include <iostream>
#include <string>
#include "Instrument.h"

Instrument::Instrument()
{
  std::cout << "Instrument - Constructor\n";
}

Instrument::~Instrument()
{
  std::cout << "Instrument - Destructor\n";
}

//Prints noise for playTimes amount
void Instrument::play(int playTimes)
{
  for( int i = 0; i < playTimes; i = i + 1 )
  {
    std::cout << sound << std::endl;
  }
}
