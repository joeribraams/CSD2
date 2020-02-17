#include <iostream>
#include "sine.h"

int main()
{
  //create sine wave
  Sine sine(220);
  std::cout << "Sine frequency: " << sine.getFreq() << "\n";

}
