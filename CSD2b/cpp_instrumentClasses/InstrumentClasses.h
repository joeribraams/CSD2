class Instrument
{
public:
  Instrument();
  ~Instrument();
  void setType(std::string newType);
  void roll(int newTimes);
  void play();

  std::string type;
  std::string Guitar;

private:
  int playTimes;
};
