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
int pitchcount = 0;

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
  generator generator;

  //sets start time for note generation
  auto start_time = std::chrono::high_resolution_clock::now();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&addsynth, &subsynth, &generator, &start_time]
    (jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // mixes synth outputs and attenuates slightly to reduce chance of clipping
      outBuf[i] = (addsynth.addSynthOut(pitch1) + subsynth.subSynthOut(pitch2)) * 0.5;
    }

    // calculates elapsed milliseconds since last note
    int time = std::chrono::duration_cast<std::chrono::milliseconds>
      (std::chrono::high_resolution_clock::now() - start_time).count();

    // gives a new note for pitch1 every second
    if (time >= 1000)
    {
      start_time = std::chrono::high_resolution_clock::now();
      pitch1 = generator.newnote();
      addsynth.envReset();

      // gives a new note for pitch2 every other note
      if (pitchcount == 1) {
        pitchcount = 0;
        pitch2 = generator.newnote();
      }
      else {
        pitchcount = 1;
      }
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
