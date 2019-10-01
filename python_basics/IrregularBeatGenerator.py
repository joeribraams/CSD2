import random as ra                                                             #Importeerd libraries en geeft het een alias
import simpleaudio as sa                                                        #""
import time as t                                                                #""
import sched as sch                                                             #""

hihat = sa.WaveObject.from_wave_file("hihat.wav")                               #Laad bestanden en definieert het als object
snare = sa.WaveObject.from_wave_file("snare.wav")                               #""
kick = sa.WaveObject.from_wave_file("kick.wav")                                 #""

while True:                                                                     #Loop voor het vragen van de maatsoort
    measure = list(input("Enter your time signature: ").split('/'))             #Vraagt de maatsoort en split op de /
    sixteenths = (int(measure[0])*4)/(int(measure[1])/4)                        #Rekend uit hoeveel 16es in de maat zitten
    if sixteenths > 20:                                                         #Als de maatsoort te veel 16es bevat:
        print('Unsupported time signature.')                                    #Waarschuwt de gebruiker
        retry_tms = input("Retry? Y/N ").upper()                                #Vraagt of de gebruiker opnieuw wilt doen, en maakt hoofdletters
        if retry_tms == "Y":                                                    #Als de gebruiker Y invult:
            continue                                                            #Herstart de Loop
        else:                                                                   #Als de gebruiker iets anders invult:
            quit()                                                              #Stopt het programma
    else:                                                                       #Als de maatsoort 20 of minder 16es bevat:
        break                                                                   #Stop de loop en ga verder

while True:                                                                     #Loop voor het vragen van de BPM is ms
    bpm = input("Enter your desired BPM: ")
    if not bpm.isdigit():
        print('Invalid input, please enter a number.')
        retry_tmp = input("Retry? Y/N ").upper()                                #Vraagt of de gebruiker opnieuw wilt doen, en maakt hoofdletters
        if retry_tmp == "Y":                                                    #Als de gebruiker Y invult
            continue                                                            #Herstart de Loop
        else:                                                                   #Als de gebruiker iets anders invult:
            quit()

    if int(bpm) > 1000 or int(bpm) < 1:                                                        #Als de tijd voor een 16e langer is dan 1 seconde:
        print('Unsupported tempo.')                                             #Waarschuwt de gebruiker
        retry_tmp = input("Retry? Y/N ").upper()                                #Vraagt of de gebruiker opnieuw wilt doen, en maakt hoofdletters
        if retry_tmp == "Y":                                                    #Als de gebruiker Y invult
            continue                                                            #Herstart de Loop
        else:                                                                   #Als de gebruiker iets anders invult:
            quit()                                                              #Stopt het programma
    else:                                                                       #Als een 16e korter dan 1 seconde is:
        note_time = (60000/int(bpm))/4                                              #Vraagt de BPM op en maakt dit de waarde van een 16e
        break                                                                   #Stop de loop en ga verder

prob = [[1, 0, 1], [0.125, 0, 0], [0.75, 0.25, 0.25], [0.25, 0.125, 0],         #Kanstabel van de 3 verschillende instrumenten
    [1, 0.75, 0.25], [0.125, 0, 0], [0.875, 0.125, 0.5], [0.125, 0.125, 0.125], #""
    [1, 0.125, 0.5], [0.25, 0, 0.125], [0.875, 0.25, 0.25],                     #""
    [0.125, 0.125, 0.25], [1, 0.75, 0.25], [0.25, 0, 0], [0.75, 0.25, 0.25],    #""
    [0.25, 0.125, 0], [1, 0.125, 0.5], [0.25, 0, 0.125], [0.875, 0.25, 0.25],   #""
    [0.125, 0.125, 0.25]]                                                       #""
sample = [hihat, snare, kick]                                                   #Maakt een lijst van de 3 samples aan.
play_notes = [[0, 0, 0] for i in range(20)]                                     #Makes empty list for the results of the comparison

for i in range(int(sixteenths)):                                                #Cycled eerst door de lijst van 16es
    for x in range(3):                                                          #Cycled daarna door de lijst van 3 instrumenten
        if ra.random() < prob[i][x]:                                            #vergelijkt de kans uit de tabel met een random nummer
            play_notes[i][x] = 1                                                #Sets place in play_notes to true
