# Import libraries and assign alias
import random as ra
import simpleaudio as sa
import time as t
import sched as sch
import threading as th
import math as m
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
        sixteenths = (int(measure[0])*4)/(int(measure[1])/4)
        if sixteenths > 20 or sixteenths < 1:
            print('Unsupported time signature.')
            retry_tms = input("Retry? Y/N ").upper()
            if retry_tms == "Y":
                continue
            else:
                quit()
        else:
            break
    else:
        print('Invalid input, please enter two positive numbers, seperated by a "/".')
        retry_tms = input("Retry? Y/N ").upper()
        if retry_tms == "Y":
            continue
        else:
            quit()


# Loop for asking the tempo, will ask to restart or quit if input unexpected.
while True:
    bpm = input("Enter your desired BPM: ")
    if not bpm.isdigit():
        print('Invalid input, please enter a positive number.')
        retry_tmp = input("Retry? Y/N ").upper()
        if retry_tmp == "Y":
            continue
        else:
            quit()
    if float(bpm) > 1000 or float(bpm) < 1:
        print('Unsupported tempo.')
        retry_tmp = input("Retry? Y/N ").upper()
        if retry_tmp == "Y":
            continue
        else:
            quit()
    else:
        note_time = (60000/float(bpm))/4000
        break

# Probability table for the 3 instruments, every second order list is a 16th
# the 3 floats are the probabilities for hihat, snare and kick respectively
prob = [[1, 0, 1], [0.125, 0, 0], [0.75, 0.25, 0.25], [0.25, 0.125, 0],
    [1, 0.75, 0.25], [0.125, 0, 0], [0.875, 0.125, 0.5], [0.125, 0.125, 0.125],
    [1, 0.125, 0.5], [0.25, 0, 0.125], [0.875, 0.25, 0.25],
    [0.125, 0.125, 0.25], [1, 0.75, 0.25], [0.25, 0, 0], [0.75, 0.25, 0.25],
    [0.25, 0.125, 0], [1, 0.125, 0.5], [0.25, 0, 0.125], [0.875, 0.25, 0.25],
    [0.125, 0.125, 0.25]]

# Makes a list of the 3 samples for playback
sample = [hihat, snare, kick]

# Makes empty list for the results of the comparison
play_notes = [[0, 0, 0] for i in range(int(sixteenths))]

# Compares te probabilities to a random float, sets place in list to true if higher
for i in range(int(sixteenths)):
    for x in range(3):
        if ra.random() < prob[i][x]:
            play_notes[i][x] = 1

# boolean to stop the playback loop
stop_playback = 0

# playback function
def playback():
    while True:
        start_time = t.time()
        for i in range(int(sixteenths)):
            for x in range(3):
                if play_notes[i][x] == 1:
                    sample[x].play()
            while t.time() - start_time < int(i+1) * note_time:
                t.sleep(0.001)
        if stop_playback:
            break

# Make the thread
playbackthread = th.thread(target=playback)
playbackthread.daemon = True

# Start the thread
playbackthread.start()

# Stops thread with any input
input("Press enter to stop")
stop_playback = 1

# Wait for both threads to finish
playbackthread.join()

MyMIDI = MIDIFile(1) # One track, defaults to format 1 (tempo track automatically created)
MyMIDI.addTempo(0, 0, int(bpm))
MyMIDI.addTimeSignature(0, 0, int(measure[0]), int(m.log2(int(measure[1]))), 24, 8)

for i in range(int(sixteenths)):
    for x in range(3):
        if x == 0:
            pitch = 42
        elif x == 1:
            pitch = 38
        elif x == 2:
            pitch = 36
        if play_notes[i][x] == 1:
            MyMIDI.addNote(0, 9, pitch, (i/4), 0.25, int(60 + (67 * prob[i][x])))


save_file = input("Do you want to save this beat? Y/N ").upper()
if save_file == "Y":
    filename = measure[0] + "_" + measure[1] + "_beat_at_" + datetime.now().strftime("%H:%M:%S") + ".mid"
    print(filename)
    with open(filename, "wb") as output_file:
        MyMIDI.writeFile(output_file)
else:
    quit()
