#include <iostream>
#include <string>
#include "InstrumentClasses.h"

InstrumentClasses::Instrument()
{
  this->type = Guitar; //default values
  playTimes = 1;
}
int InstrumentClasses::setType(std::string newType)
{
  this->type = newType;
}

int InstrumentClasses::roll(int newTimes)
{
  this->playTimes = newTimes;
}

int InstrumentClasses::play()
{
  for( int i = 0; i < playTimes; i = i + 1 )
  {
    std::cout << type << std::endl;
  }
}
