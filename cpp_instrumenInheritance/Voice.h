class Voice
{
public:
  //Constructor and Destructor
  Voice();
  ~Voice();

  //Methods
  void play(int playTimes);

private:
  int rangeLow = 46;
  int rangeHigh = 70;
};
