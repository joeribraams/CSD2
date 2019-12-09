class Synth
{
public:
  //Constructor and Destructor
  Synth();
  ~Synth();

  //Methods
  void play(int playTimes);

private:
  //Preset range of instrument
  int rangeLow = 0;
  int rangeHigh = 127;
};
