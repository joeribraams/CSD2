#include <iostream>
#include <thread>
#include <ctime>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "saw.h"
#include "subsynth.h"
#include "addsynth.h"
#include "generator.h"

float pitch1 = 440;
float pitch2 = 110;

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);

  // inits the synth modules
  addSynth addsynth;
  subSynth subsynth;

  // inits the note generators
  generator generator1;
  generator generator2;

  //sets start time for note generation
  time_t start_time1 = time(NULL);
  time_t start_time2 = time(NULL);

  //assign a function to the JackModule::onProces
  jack.onProcess = [&addsynth, &subsynth, &generator1, &generator2, &start_time1, &start_time2](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // mixes synth outputs and attenuates slightly to reduce chance of clipping
      outBuf[i] = (addsynth.addSynthOut(pitch1) + subsynth.subSynthOut(pitch2)) * 0.7;
    }

    // gives current time for note generation
    time_t current_time = time(NULL);

    // gives a new note for pitch1 every second
    if (current_time - start_time1 >= 1)
    {
      start_time1 = current_time;
      pitch1 = generator1.newnote();
    }
    // gives a new note for pitch2 every 2 seconds
    if (current_time - start_time2 >= 2)
    {
      start_time2 = current_time;
      pitch2 = generator2.newnote();
    }

    return 0;
  };

  jack.autoConnect();


  //keep the program running and listen for user input, q = quit
  std::cout << "\nPress enter to quit.\n";
  bool running = true;
  while (running)
  {
    if (std::cin.get())
    {
      running = false;
      jack.end();
      break;
    }
  }

  //end the program
  return 0;
} // main()
