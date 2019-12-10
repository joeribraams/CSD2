#include <iostream>
#include <string>
#include "Guitar.h"
#include "Voice.h"
#include "Synth.h"


//calls classes and plays come combinations
int main()
{
  Guitar guitar1;
  Synth synth1;
  Voice voice1;

  guitar1.play(5);
  synth1.play(2);
  voice1.play(3);

  return 0;
}
