import simpleaudio as sa        #Importeerd library en geeft het een alias
wave_obj = sa.WaveObject.from_wave_file("click.wav") #Laad het bestand en definieert het als object
Playtimes = int(input('Enter how many times you want to play the file: ')) #Vraagt hoe vaak het af moet spelen en maakt integer
i = 1                           #Maakt iteratie variabele aan

while i <= Playtimes:           #Loopet het even vaak als door de gebruiker aangegeven
    play_obj = wave_obj.play()  #Speelt het bestand af
    play_obj.wait_done()        #Wacht tot het afspelen klaar is voordat het afsluit
    i += 1
