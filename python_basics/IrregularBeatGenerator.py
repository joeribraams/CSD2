import random as ra                                                             #Importeerd libraries en geeft het een alias
import simpleaudio as sa                                                        #""
import time as t                                                                #""
import sched as sch                                                             #""

hihat = sa.WaveObject.from_wave_file("hihat.wav")                               #Laad bestanden en definieert het als object
snare = sa.WaveObject.from_wave_file("snare.wav")                               #""
kick = sa.WaveObject.from_wave_file("kick.wav")                                 #""

s = sch.scheduler(t.time, t.sleep)                                              #Maakt scheduler object aan

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

while True:                                                                     #Loop voor het vragen van de BPM
    note_time = (60/int(input("Enter your desired BPM: ")))/4                   #Vraagt de BPM op en maakt dit de waarde van een 16e
    if note_time > 1:                                                           #Als de tijd voor een 16e langer is dan 1 seconde:
        print('Unsupported tempo.')                                             #Waarschuwt de gebruiker
        retry_tmp = input("Retry? Y/N ").upper()                                #Vraagt of de gebruiker opnieuw wilt doen, en maakt hoofdletters
        if retry_tmp == "Y":                                                    #Als de gebruiker Y invult
            continue                                                            #Herstart de Loop
        else:                                                                   #Als de gebruiker iets anders invult:
            quit()                                                              #Stopt het programma
    else:                                                                       #Als een 16e korter dan 1 seconde is:
        break                                                                   #Stop de loop en ga verder

prob = [[1, 0, 1], [0.125, 0, 0], [0.75, 0.25, 0.25], [0.25, 0.125, 0], [1, 0.75, 0.25], [0.125, 0, 0], [0.875, 0.125, 0.5], [0.125, 0.125, 0.125], [1, 0.125, 0.5], [0.25, 0, 0.125], [0.875, 0.25, 0.25], [0.125, 0.125, 0.25], [1, 0.75, 0.25], [0.25, 0, 0], [0.75, 0.25, 0.25], [0.25, 0.125, 0], [1, 0.125, 0.5], [0.25, 0, 0.125], [0.875, 0.25, 0.25], [0.125, 0.125, 0.25]]
rand = [[ra.random(), ra.random(), ra.random()] for i in range(20)]             #Maakt een lijst met 3 lijsten van willekeurige getallen aan.
sample = [hihat, snare, kick]                                                   #Maakt een lijst van de 3 samples aan.

print('Press ctrl-shift-c to stop.')                                            #Alleen zodat de gebruiker weet hoe je sport, zorgt voor een error.
while True:                                                                     #Loopt het patroon todat je stopt
    for i in range(int(sixteenths)):                                            #Cycled eerst door de lijst van 16es
        for x in range(3):                                                      #Cycled daarna door de lijst van 3 instrumenten
            if rand[i][x] < prob[i][x]:                                         #vergelijkt de kans uit de tabel met een random nummer
                sch.enter((i+1)*note_time, 1, sample[x].play)                   #Laat de scheduler i keer het de tijd van een 16e wachten en speelt de sample
    sch.run()                                                                   #Runt de scheduler
