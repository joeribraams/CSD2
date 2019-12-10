#include "Instrument.h"

class Synth : public Instrument
{
public:
  //Constructor and Destructor
  Synth();
  ~Synth();

  //variables
  int type = 2;

private:
  //Preset range of instrument
  int rangeLow = 0;
  int rangeHigh = 127;
};
