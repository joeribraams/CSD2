#include <iostream>
#include <math.h>
#include "AudioFile.h"
#include "fir.h"

//Make the files and buffer objects
AudioFile<double> audioFile;
AudioFile<double> impulse;
AudioFile<double>::AudioBuffer buffer;

int main()
{
  //Load the file and get data
  audioFile.load("audio.wav");
  int numSamples = audioFile.getNumSamplesPerChannel();
  bool stereo = audioFile.isStereo();

  //Load the impulse response
  impulse.load("impulse.wav");
  int order = impulse.getNumSamplesPerChannel();

  //Make the fir objects
  Fir fir1(order);
  Fir fir2(order);

  //Add every sample of the IR as a Coeff
  for (int i = order; i >= 0; i--)
  {
    fir1.addCoeffs(impulse.samples[0][i]);
    fir2.addCoeffs(impulse.samples[1][i]);
  }

  //init buffers, 2 for stereo
  buffer.resize(2);
  buffer[0].resize(numSamples);
  buffer[1].resize(numSamples);

  //run the filter for every sample
  for (int i = 0; i < numSamples; i++)
  {
  	buffer[0][i] = fir1.filter(audioFile.samples[0][i]);

    if(stereo)
    {
      buffer[1][i] = fir2.filter(audioFile.samples[stereo][i]);
    }
  }

  //write buffer and file
  audioFile.setAudioBuffer(buffer);
  audioFile.save("output.wav");

  return 1;
}
