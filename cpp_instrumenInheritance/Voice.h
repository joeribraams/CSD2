#include "Instrument.h"

class Voice : public Instrument
{
public:
  //Constructor and Destructor
  Voice();
  ~Voice();

  //variables
  int type = 1;

private:
  //Preset range of instrument
  int rangeLow = 46;
  int rangeHigh = 70;
};
