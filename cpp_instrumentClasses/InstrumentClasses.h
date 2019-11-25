class Instrument
{
public:
  Instrument();
  ~Instrument();
  int setType(std::string newType);
  int roll(int newTimes);
  int play();

  std::string type;
  
private:
  int playTimes;
};
