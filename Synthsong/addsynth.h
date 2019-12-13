#pragma once
#include "sine.h"
#include "saw.h"

class addSynth
{
public:
  //Constructor and destructor
  addSynth();
  ~addSynth();

  float addSynthOut(float frequency);

  float output;
};
