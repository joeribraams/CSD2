#include "Instrument.h"

class Synth : public Instrument
{
public:
  //Constructor and Destructor
  Synth();
  ~Synth();

private:
  //Preset range of instrument
  int rangeLow = 0;
  int rangeHigh = 127;
};
