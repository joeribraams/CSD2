#pragma once
#include "saw.h"

class subSynth
{
public:
  //Constructor and destructor
  subSynth();
  ~subSynth();

  float subSynthOut(float frequency);

  float output;
};
