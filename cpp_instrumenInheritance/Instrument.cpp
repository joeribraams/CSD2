#include <iostream>
#include <string>
#include "Instrument.h"
#include "Gitaar.h"
#include "Synth.h"
#include "Voice.h"

Instrument::Instrument()
{
  std::cout << "Instrument - Constructor\n";
  type = 0; //default values
  playTimes = 1;
}

Instrument::~Instrument()
{
  std::cout << "Instrument - Destructor\n";
}

void Instrument::setType(int newType)
{
  this->type = newType;
}

void Instrument::roll(int newTimes)
{
  this->playTimes = newTimes;
}


//calls subclass play function
void Instrument::play()
{
  if (type == 0){
    Gitaar Gitaar1;
    Gitaar1.play(playTimes);
  }
  if (type == 1){
    Synth Synth1;
    Synth1.play(playTimes);
  }
  if (type == 2){
    Voice Voice1;
    Voice1.play(playTimes);
  }
}
