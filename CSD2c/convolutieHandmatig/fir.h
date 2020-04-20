#pragma once

#include <vector>
#include <iostream>

class Fir
{
public:
	//init vectors
	std::vector<double>Coeffs;
	std::vector<double>Buffer;

	//constructor and destructor
	Fir(int order);
	~Fir();

	//write coeffs to vector
  void addCoeffs(double coeff);

	//input and output
  double filter(double input);

	//wrap function to stay within buffer
  int wrap(int input);

  int buffIdx = 0;
};
