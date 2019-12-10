#include <iostream>
#include <string>
#include "Guitar.h"

//Constructor also prints instrument range
Guitar::Guitar() : Instrument()
{
  std::cout << "Guitar - Constructor, range is: " << rangeLow << "," << rangeHigh << std::endl;
  sound = "Plink";
}

//Destructor
Guitar::~Guitar()
{
  std::cout << "Guitar - Destructor\n";
}
