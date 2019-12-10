#pragma once

class Oscillator
{
public:
  //Constructor and destructor
  Oscillator();
  ~Oscillator();

  float amplitude;
  float frequency;
  float samplerate = jack.getSamplerate();
};
