class Instrument
{
public:
  //Constructor and Destructor
  Instrument();
  ~Instrument();

  //Methods
  void setType(int newType);
  void roll(int newTimes);
  void play();

  //Class variables
  int type;
  int playTimes;
};
