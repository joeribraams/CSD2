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
  float notes[7] = {261.6, 293.7, 329.7, 349.2, 392, 440, 493};

  int i = rand() % 7;
  std::cout << notes[i] << std::endl;
  return notes[i];
}
