#pragma once
#include "saw.h"

class subSynth
{
public:
  //Constructor and destructor
  subSynth();
  ~subSynth();

  //adds the saws and outputs them
  float subSynthOut(float frequency);

private:
  float output;
};
