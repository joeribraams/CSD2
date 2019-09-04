import simpleaudio as sa    #Importeerd library en geeft het een alias
wave_obj = sa.WaveObject.from_wave_file("click.wav") #Laad het bestand en definieert het als object
play_obj = wave_obj.play()  #Speelt het bestand af
play_obj.wait_done()        #Wacht tot het afspelen klaar is voordat het afsluit
