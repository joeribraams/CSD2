#include "Instrument.h"

class Guitar : public Instrument
{
public:
  //Constructor and Destructor
  Guitar();
  ~Guitar();

private:
  //Preset range of instrument
  int rangeLow = 40;
  int rangeHigh = 80;
};
