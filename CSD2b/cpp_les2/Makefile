osc_test: Oscillator.o Oscillator_test.o
	g++ -o osc_test Oscillator.o Oscillator_test.o

Oscillator.o: Oscillator.cpp Oscilator.h
	g++ -c Oscillator.cpp

Oscillator_test.o: Oscillator_test.cpp Oscilator.h
	g++ -c Oscillator_test.cpp

clean:
	rm -f *.o osc_test
