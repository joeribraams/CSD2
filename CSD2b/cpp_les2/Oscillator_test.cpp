#include <iostream>
#include "Oscillator.h"

int main()
{
  Oscillator oscillator(220);
  oscillator.setFreq(-1);
  std::cout << "Oscillator freq is " << oscillator.getFreq() << "\n";
  // end of main
  return 0;
}
