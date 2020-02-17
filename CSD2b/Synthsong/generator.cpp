#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "generator.h"

generator::generator()
{
  std::cout << "generator - constructor\n";
}

generator::~generator()
{
  std::cout << "generator - destructor\n";
}

float generator::newnote()
{
  // list of c major scale
  float notes[7] = {130.8, 146.85, 164.85, 174.6, 196, 220, 246.5};
  // random number between 0 and 6, to take from the list
  int i = rand() % 7;
  // random number octave multiplier
  int x = (rand() % 4) + 1;
  return (notes[i]) * x;
}
