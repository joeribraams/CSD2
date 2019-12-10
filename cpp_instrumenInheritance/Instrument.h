#pragma once

class Instrument
{
public:
  //Constructor and Destructor
  Instrument();
  ~Instrument();

  //Methods
  void play(int playTimes);

  //Class variables
  int playTimes;

protected:
  std::string sound;
};
