#include <iostream>
#include <string>
#include "InstrumentClasses.h"

Instrument::Instrument()
{
  type = "Plink"; //default values
  playTimes = 1;
}

Instrument::~Instrument()
{
  std::cout << "Instrument - Destructor\n";
}

void Instrument::setType(std::string newType)
{
  this->type = newType;
}

void Instrument::roll(int newTimes)
{
  this->playTimes = newTimes;
}

void Instrument::play()
{
  for( int i = 0; i < playTimes; i = i + 1 )
  {
    std::cout << type << std::endl;
  }
}
