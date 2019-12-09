#include <iostream>
#include <string>
#include "Instrument.h"

int Guitar = 0; //"Plink"
int Synth = 1; //"Bliep"
int Voice = 2; //"Aaaaaa"

int main()
{
  Instrument inst1;
  Instrument inst2;

  inst1.roll(5);
  inst1.play();
  inst2.setType(Voice);
  inst2.roll(2);
  inst2.play();
  inst1.setType(Synth);
  inst1.roll(3);
  inst1.play();

  return 0;
}
