#include <iostream>

class HelloWorld
{
  public:
    HelloWorld() //constructor
    {
      year=1970; //default value
    }

    int setYear(int newyear)
    {
      year = newyear;
    }

    int hello()
    {
      std::cout << "Hello world!" << year << std::endl;
    }

    int year;
};

int main()
{
  HelloWorld hw1;
  HelloWorld hw2;

  hw1.hello();
  hw2.setYear(2012);
  hw2.hello();
  hw2.setYear(2020);
  hw2.hello();

  return 0;
}
