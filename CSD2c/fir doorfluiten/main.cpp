#include <complex>
#include <iostream>
#include <math.h>

int main()
{
  std::cout << "First order FIR filter calculator.\n";

  std::cout << "Enter the first coëfficent:\n";
  double coef0;
  std::cin >> coef0;

  std::cout << "Enter the second coëfficent:\n";
  double coef1;
  std::cin >> coef1;

  std::cout << "Enter the amount of steps:\n";
  double steps;
  std::cin >> steps;
  steps = M_PI / steps;

  std::complex<double> i (0, 1.0);

  for (double w = 0.0; w <= M_PI; w += steps)
  {
    double output = abs(coef0 + coef1 * exp(-i * w));
    std::cout << "Omega = " << w << ", H = " << output << "\n";
  }
  return 1;
}
