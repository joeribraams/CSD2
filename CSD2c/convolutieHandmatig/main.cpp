#include <iostream>
#include <math.h>
#include "AudioFile.h"
#include "fir.h"

//Make the file and buffer objects
AudioFile<double> audioFile;
AudioFile<double>::AudioBuffer buffer;


int main()
{
  //Load the file and get data
  audioFile.load("audio.wav");
  int numSamples = audioFile.getNumSamplesPerChannel();
  bool stereo = audioFile.isStereo();

  //init buffers, 2 for stereo
  buffer.resize(2);
  buffer[0].resize(numSamples);
  buffer[1].resize(numSamples);

  //UI for data
  std::cout << "Nth order FIR filter calculator.\n";
  std::cout << "Enter the FIR order: ";
  int order;
  std::cin >> order;

  //Make the fir objects
  Fir fir1(order);
  Fir fir2(order);

  //UI for coëfficents
  for (int i = 0; i <= order; i++)
  {
    std::cout << "Enter coëfficent number " << (i + 1) << ": ";
    double coeff;
    std::cin >> coeff;
    fir1.addCoeffs(coeff);
    fir2.addCoeffs(coeff);
  }

  //run the filter for every sample
  for (int i = 0; i < numSamples; i++)
  {
  	buffer[0][i] = fir1.filter(audioFile.samples[0][i]);

    //do the second channel if its a stereo file
    if(stereo)
    {
      buffer[1][i] = fir2.filter(audioFile.samples[1][i]);
    }
  }

  //write buffer and file
  audioFile.setAudioBuffer(buffer);
  audioFile.save("output.wav");

  std::cout << "File written as output.wav\n";

  return 1;
}
