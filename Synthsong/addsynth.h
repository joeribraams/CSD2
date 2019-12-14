#pragma once
#include "sine.h"
#include "saw.h"

class addSynth
{
public:
  //Constructor and destructor
  addSynth();
  ~addSynth();

  //member functions
  float addSynthOut(float frequency);

private:
  float output;
};
