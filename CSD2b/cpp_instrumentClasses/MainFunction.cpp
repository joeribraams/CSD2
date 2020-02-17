#include <iostream>
#include <string>
#include "InstrumentClasses.h"

//Strings in place of sound generation
std::string guitar = "Plink";
std::string synth = "Bliep";
std::string voice = "Aaaaaa";

int main()
{
  //Initialize instrument classes
  Instrument inst1(synth);
  Instrument inst2;

  //Play instruments with different types and repetitions
  inst1.roll(5);
  inst1.play();
  inst2.setType(voice);
  inst2.roll(2);
  inst2.play();
  inst1.setType(synth);
  inst1.roll(3);
  inst1.play();

  //End the main function.
  return 0;
}
