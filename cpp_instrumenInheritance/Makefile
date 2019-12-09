MainFunction: Instrument.o MainFunction.o Gitaar.o Synth.o Voice.o
	g++ -o test Instrument.o MainFunction.o Gitaar.o Synth.o Voice.o

Gitaar.o: Gitaar.cpp Gitaar.h
	g++ -c Gitaar.cpp

Synth.o: Synth.cpp Synth.h
	g++ -c Synth.cpp

Voice.o: Voice.cpp Voice.h
	g++ -c Voice.cpp

Instrument.o: Instrument.cpp Instrument.h Gitaar.o Synth.o Voice.o
	g++ -c Instrument.cpp

MainFunction.o: MainFunction.cpp Instrument.h
	g++ -c MainFunction.cpp

clean:
	rm -f *.o osc_test
