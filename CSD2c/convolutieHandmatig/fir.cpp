#include "fir.h"

//constructor and destructor
Fir::Fir(int order)
{
  //Allocate memory to vector
  Buffer.resize(order + 1);
  Buffer.reserve(order + 1);
}


Fir::~Fir()
{

}

//write coeffs to vector
void Fir::addCoeffs(double coeff)
{
	Coeffs.push_back(coeff);
}

//input and output
double Fir::filter(double input)
{
  Buffer[buffIdx] = input;

  //reset output
  double output = 0;

  //for every coeff of the filter
  for(int i = 0; i < Coeffs.size(); i++)
  {
    //add the buffer times the corresponding coeff to the output
    output += Buffer[wrap(buffIdx + i)] * Coeffs[i];
  }

  buffIdx = wrap(++buffIdx);

  return output;
}

//wrap function to stay within buffer
int Fir::wrap(int input)
{
  if (input >= 0)
  {
    if (input < Buffer.size())
    {
      return input;
    }
    else
    {
      return input - Buffer.size();
    }
  }
  else
  {
    return input + Buffer.size();
  }
}
