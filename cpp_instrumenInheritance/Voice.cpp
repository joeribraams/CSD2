#include <iostream>
#include <string>
#include "Voice.h"

//Constructor also prints instrument range
Voice::Voice()
{
  std::cout << "Voice - Constructor, range is: " << rangeLow << "," << rangeHigh << std::endl;
}

//Destructor
Voice::~Voice()
{
  std::cout << "Voice - Destructor\n";
}

//Prints noise for playTimes amount
void Voice::play(int playTimes)
{
  for( int i = 0; i < playTimes; i = i + 1 )
  {
    std::cout << "Aaaaaa" << std::endl;
  }
}
