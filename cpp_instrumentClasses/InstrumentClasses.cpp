#include <iostream>
#include <string>
#include "InstrumentClasses.h"

//Constructor
Instrument::Instrument()
{
  type = "Plink"; //default values
  playTimes = 1;
}

Instrument::Instrument(std::string type)
{
  setType(type);
  playTimes = 1;
}
//Destructor
Instrument::~Instrument()
{
  std::cout << "Instrument - Destructor\n";
}

//Change the 'sound' i.e. output string
void Instrument::setType(std::string newType)
{
  this->type = newType;
}

//Save the amount of repeats
void Instrument::roll(int newTimes)
{
  this->playTimes = newTimes;
}

//Print the stings for an amount of repeats
void Instrument::play()
{
  for( int i = 0; i < playTimes; i = i + 1 )
  {
    std::cout << type << std::endl;
  }
}
