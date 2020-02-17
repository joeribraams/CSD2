#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "circBuffer.h"
#include "stereoDelay.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

// preset settings
float delayTime = 350;
float feedback = 0.6;
float wetLevel = 0.6;
float dryLevel = 0.0;

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float sampleRate = jack.getSamplerate();

  // load settings from arguments
  if(argc >= 2) delayTime = (float) atof(argv[1]);

  if(argc >= 3) feedback = (float) atof(argv[2]);

  if(argc >= 4) wetLevel = (float) atof(argv[3]);

  if(argc >= 5) dryLevel = (float) atof(argv[4]);

  // create the stereoDelay instance
  stereoDelay stereoDelay(sampleRate, delayTime, feedback, wetLevel, dryLevel);

  // assign a function to the JackModule::onProces
  jack.onProcess = [&stereoDelay](jack_default_audio_sample_t *inBuf,
  jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes)
  {
    for(unsigned int i = 0; i < nframes; i++)
    {
      // read the current input sample
      stereoDelay.write(inBuf[i]);
      // write the output samples for left and right channel
      outBufL[i] = stereoDelay.readLeft();
      outBufR[i] = stereoDelay.readRight();
    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' to quit.\n";
  std::cout << "Press 't' change delay time in milliseconds.\n";
  std::cout << "Press 'f' change feedback between 0 and 1.\n";
  std::cout << "Press 'w' change wet level between 0 and 1.\n";
  std::cout << "Press 'd' change dry level between 0 and 1.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      // user input for quiting and changing settings
      case 'q':
        running = false;
        jack.end();
        break;
      case 't':
        float newTime;
        std::cin >> newTime;
        stereoDelay.setTime(newTime);
        break;
      case 'f':
        float newFeed;
        std::cin >> newFeed;
        stereoDelay.setFeedback(newFeed);
        break;
      case 'w':
        float newWet;
        std::cin >> newWet;
        stereoDelay.setWetLevel(newWet);
        break;
      case 'd':
        float newDry;
        std::cin >> newDry;
        stereoDelay.setWetLevel(newDry);
        break;
    }
  }

  //end the program
  return 0;
} // main()
