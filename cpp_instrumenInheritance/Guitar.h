#include "Instrument.h"

class Guitar : public Instrument
{
public:
  //Constructor and Destructor
  Guitar();
  ~Guitar();

  //variables
  int type = 0;

private:
  //Preset range of instrument
  int rangeLow = 40;
  int rangeHigh = 80;
};
