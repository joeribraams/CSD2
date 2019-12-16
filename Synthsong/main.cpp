#include <iostream>
#include <thread>
#include <chrono>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "saw.h"
#include "subsynth.h"
#include "addsynth.h"
#include "generator.h"

float pitch1 = 523.2;
float pitch2 = 130.8;

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
  auto start_time1 = std::chrono::high_resolution_clock::now();
  auto start_time2 = std::chrono::high_resolution_clock::now();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&addsynth, &subsynth, &generator1, &generator2, &start_time1, &start_time2]
    (jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // mixes synth outputs and attenuates slightly to reduce chance of clipping
      outBuf[i] = (addsynth.addSynthOut(pitch1) + subsynth.subSynthOut(pitch2)) * 0.7;
    }

    // calculates elapsed milliseconds since last note
    int time1 = std::chrono::duration_cast<std::chrono::milliseconds>
      (std::chrono::high_resolution_clock::now() - start_time1).count();
    // gives a new note for pitch1 every second
    if (time1 >= 1000)
    {
      start_time1 = std::chrono::high_resolution_clock::now();
      pitch1 = generator1.newnote();
      addsynth.envReset();
    }

    // calculates elapsed milliseconds since last note
    int time2 = std::chrono::duration_cast<std::chrono::milliseconds>
      (std::chrono::high_resolution_clock::now() - start_time2).count();
    // gives a new note for pitch2 every 2 seconds
    if (time2 >= 2000)
    {
      start_time2 = std::chrono::high_resolution_clock::now();
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
