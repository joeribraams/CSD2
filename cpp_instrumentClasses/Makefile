MainFunction: InstrumentClasses.o MainFunction.o
	g++ -o osc_test InstrumentClasses.o MainFunction.o

InstrumentClasses.o: InstrumentClasses.cpp InstrumentClasses.h
	g++ -c Oscillator.cpp

Oscillator_test.o: MainFunction.cpp InstrumentClasses.h
	g++ -c MainFunction.cpp

clean:
	rm -f *.o osc_test
