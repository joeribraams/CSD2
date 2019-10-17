# Import libraries and assign aliases
import random
import simpleaudio as sa
import time
import threading
import math
from midiutil import MIDIFile
from datetime import datetime

# Load files and define as objects
hihat = sa.WaveObject.from_wave_file("hihat.wav")
snare = sa.WaveObject.from_wave_file("snare.wav")
kick = sa.WaveObject.from_wave_file("kick.wav")

# Loop for asking the time signature, will ask to restart or quit if input unexpected.
while True:
    measure = list(input("Enter your time signature: ").split('/'))
    if len(measure) == 2 and measure[0].isdigit() and measure[1].isdigit() and int(measure[0]) >= 1 and int(measure[1]) >= 1:
        # Calculates amount of 16th notes for given time signature
        sixteenths = (int(measure[0])*4)/(int(measure[1])/4)
        if sixteenths > 28 or sixteenths < 1:
            print('Unsupported time signature.')
            retry_tms = input("Retry? Y/N ").upper()
            if retry_tms == "Y":
                continue
            else:
                quit()
        else:
            break
    else:
        print('Invalid input, please enter two positive, whole numbers, seperated by a "/".')
        retry_tms = input("Retry? Y/N ").upper()
        if retry_tms == "Y":
            continue
        else:
            quit()


# Loop for asking the tempo, will ask to restart or quit if input unexpected.
while True:
    bpm = input("Enter your desired BPM: ")
    if not bpm.isdigit():
        print('Invalid input, please enter a positive, whole number.')
        retry_tmp = input("Retry? Y/N ").upper()
        if retry_tmp == "Y":
            continue
        else:
            quit()
    if float(bpm) > 1000 or float(bpm) < 1:
        print('Unsupported tempo, please stay within 1 and 999 BPM.')
        retry_tmp = input("Retry? Y/N ").upper()
        if retry_tmp == "Y":
            continue
        else:
            quit()
    else:
        # Calculates time for 16th note step from bpm
        note_time = (60000/float(bpm))/4000
        break

# Probability table for the 3 instruments, every second order list is a 16th
# The 3 floats are the probabilities for hihat, snare and kick respectively
prob = [[1, 0, 1], [0.125, 0, 0], [0.75, 0.25, 0.25], [0.25, 0.125, 0],
    [1, 0.75, 0.25], [0.125, 0, 0], [0.875, 0.125, 0.5], [0.125, 0.125, 0.125],
    [1, 0.125, 0.5], [0.25, 0, 0.125], [0.875, 0.25, 0.25],
    [0.125, 0.125, 0.25], [1, 0.75, 0.25], [0.25, 0, 0], [0.75, 0.25, 0.25],
    [0.25, 0.125, 0], [1, 0.125, 0.5], [0.25, 0, 0.125], [0.875, 0.25, 0.25],
    [0.125, 0.125, 0.25], [1, 0.75, 0.25], [0.125, 0, 0], [0.875, 0.125, 0.5],
    [0.125, 0.125, 0.125], [1, 0.125, 0.5], [0.25, 0.125, 0],
    [0.875, 0.25, 0.25], [0.125, 0.25, 0.125]]

# Makes a list of the 3 samples for playback
sample = [hihat, snare, kick]

# Loop for replaying with the same settings
while True:
    # Compares the probabilities to a random float, sets place in empty list to true if higher
    play_notes = [[0, 0, 0] for i in range(int(sixteenths))]
    for i in range(int(sixteenths)):
        for x in range(3):
            if random.random() < prob[i][x]:
                play_notes[i][x] = 1

    # Boolean to stop the playback loop
    stop_playback = 0

    # Playback function
    def playback():
        while True:
            start_time = time.time()
            # Loops through the list of 16th note steps and tests all 3 instruments
            for i in range(int(sixteenths)):
                for x in range(3):
                    if play_notes[i][x] == 1:
                        sample[x].play()
                while time.time() - start_time < int(i+1) * note_time:
                    time.sleep(0.001)
            if stop_playback:
                break

    # Makes and starts the thread
    playbackthread = threading.Thread(target=playback)
    playbackthread.daemon = True
    playbackthread.start()

    # Stops thread with any input
    input("Press enter to stop")
    stop_playback = 1

    # Wait for thread to finish
    playbackthread.join()

    # Creates the midi file with tempo and time signature
    MyMIDI = MIDIFile(1)
    MyMIDI.addTempo(0, 0, int(bpm))
    MyMIDI.addTimeSignature(0, 0, int(measure[0]), int(math.log2(int(measure[1]))), 24, 8)

    # Writes notes to midi file
    for i in range(int(sixteenths)):
        for x in range(3):
            # Choose note per drum according to general midi
            if x == 0:
                pitch = 42
            elif x == 1:
                pitch = 38
            elif x == 2:
                pitch = 36
            if play_notes[i][x] == 1:
                # Probability gets scaled to velocity, higher chance is more likely to be an accent
                MyMIDI.addNote(0, 9, pitch, (i/4), 0.25, int(60 + (67 * prob[i][x])))

    # Asks to save file, will save with time signature and current time in filename
    save_file = input("Do you want to save this beat? Y/N ").upper()
    if save_file == "Y":
        filename = measure[0] + "_" + measure[1] + "_beat_at_" + datetime.now().strftime("%H:%M:%S") + ".mid"
        with open(filename, "wb") as output_file:
            MyMIDI.writeFile(output_file)
            print("Saved as: " + filename)

    # Asks to make a new beat with the same settings
    replay = input("Retry with the same settings? Y/N ").upper()
    if replay == "Y":
        continue
    else:
        quit()
