#include <iostream>
#include "Oscillator.h"

Oscillator::Oscillator(float freq) : freq(freq)
{
  std::cout << "Oscillator - Constructor\n";
}

Oscillator::~Oscillator()
{
  std::cout << "Oscillator - Destructor\n";
}

void Oscillator::setFreq(float freq)
{
  if(freq < 0 || freq > 22050) {
    std::cout << "ERROR, cant set frequency to " << freq << "\n";
    return;
  }
  std::cout << "Oscillator - setFreq\n";
}

float Oscillator::getFreq()
{
  std::cout << "Oscillator - getFreq\n";
  return freq;
}
