import simpleaudio as sa                                #Importeerd library en geeft het een alias
import time as t                                        #Importeerd library en geeft het een alias
wave_obj = sa.WaveObject.from_wave_file("click.wav")    #Laad het bestand en definieert het als object

in_list = list(input('First enter your desired BPM, then add your relative note lenths where 1 is a quarter note, 0.5 an eigth note ect, all seperated by spaces: ').split(' ')) #input list en haalt spaties er uit
quarter = 60/float(in_list.pop(0))                      #haalt de BPM uit de eerste plaats van de lijst en berekend tijd van een kwartnoot

t.sleep(1)                                              #wacht even voor hij begint met afspelen
for note in in_list:                                    #loopt zo vaak als er nog dingen in de lijst staan
    play_obj = wave_obj.play()                          #speelt de sample
    t.sleep(float(note)*quarter)                        #wacht zolang als de nootlengte keer tijd duurt
