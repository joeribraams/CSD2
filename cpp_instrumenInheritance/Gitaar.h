class Gitaar
{
public:
  //Constructor and Destructor
  Gitaar();
  ~Gitaar();

  //Methods
  void play(int playTimes);

private:
  //Preset range of instrument
  int rangeLow = 40;
  int rangeHigh = 80;
};
