class Instrument
{
public:
  //Constructor and Destructor
  Instrument();
  ~Instrument();

  //Methods
  void setType(std::string newType);
  void roll(int newTimes);
  void play();

  //Class variables
  std::string type;
  std::string Guitar;

private:
  int playTimes;
};
