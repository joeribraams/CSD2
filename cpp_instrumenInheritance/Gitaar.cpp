#include <iostream>
#include <string>
#include "Gitaar.h"

//Constructor also prints instrument range
Gitaar::Gitaar()
{
  std::cout << "Gitaar - Constructor, range is: " << rangeLow << "," << rangeHigh << std::endl;
}

//Destructor
Gitaar::~Gitaar()
{
  std::cout << "Gitaar - Destructor\n";
}

//Prints noise for playTimes amount
void Gitaar::play(int playTimes)
{
  for( int i = 0; i < playTimes; i = i + 1 )
  {
    std::cout << "Plink" << std::endl;
  }
}
