#pragma once

class Oscillator
{
public:
  //Constructor and destructor
  Oscillator();
  ~Oscillator();

  void phaseReset();

  //member variables
protected:
  float phase;
  float amplitude;
  float frequency;
};
