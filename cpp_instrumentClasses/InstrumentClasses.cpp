#include <iostream>
#include <string>

std::string Guitar = "Plink";
std::string Synth = "Bliep";
std::string Voice = "Aaaaaa";

class Instrument
{
  public:
    Instrument() //constructor
    {
      type = Guitar; //default values
      playAmount = 1;
    }

    int setType(std::string newType)
    {
      type = newType;
    }

    int roll(int rollTimes)
    {
      playAmount = rollTimes;
    }

    int play()
    {
      for( int i = 0; i < playAmount; i = i + 1 ) {
        std::cout << type << std::endl;
      }
    }

    std::string type;
    int playAmount;
};

int main()
{
  Instrument inst1;
  Instrument inst2;

  inst1.roll(5);
  inst1.play();
  inst2.setType(Voice);
  inst2.roll(2);
  inst2.play();
  inst1.setType(Synth);
  inst1.roll(3);
  inst1.play();

  return 0;
}
