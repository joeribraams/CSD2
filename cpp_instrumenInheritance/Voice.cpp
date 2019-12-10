#include <iostream>
#include <string>
#include "Voice.h"

//Constructor also prints instrument range
Voice::Voice() : Instrument()
{
  std::cout << "Voice - Constructor, range is: " << rangeLow << "," << rangeHigh << std::endl;
  sound = "Aaaaa";
}

//Destructor
Voice::~Voice()
{
  std::cout << "Voice - Destructor\n";
}
