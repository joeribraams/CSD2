#include <iostream>

class Oscillator
{
public:
  Oscillator(float freq);
  ~Oscillator();

  void setFreq(float freq);
  float getFreq();

private:
  float freq;
};

Oscillator::Oscillator(float freq)
{
  this->freq = freq;
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
  this->freq = freq;
  std::cout << "Oscillator - setFreq\n";
}

float Oscillator::getFreq()
{
  return freq;
  std::cout << "Oscillator - getFreq\n";
}

int main()
{
  Oscillator oscillator(220);
  oscillator.setFreq(-1);
  std::cout << "Oscillator freq is " << oscillator.getFreq() << "\n";
  // end of main
  return 0;
}
