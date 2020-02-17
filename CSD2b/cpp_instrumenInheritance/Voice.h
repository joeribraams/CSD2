#include "Instrument.h"

class Voice : public Instrument
{
public:
  //Constructor and Destructor
  Voice();
  ~Voice();

private:
  //Preset range of instrument
  int rangeLow = 46;
  int rangeHigh = 70;
};
