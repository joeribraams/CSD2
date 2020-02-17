MainFunction: InstrumentClasses.o MainFunction.o
	g++ -o test InstrumentClasses.o MainFunction.o

InstrumentClasses.o: InstrumentClasses.cpp InstrumentClasses.h
	g++ -c InstrumentClasses.cpp

MainFunction.o: MainFunction.cpp InstrumentClasses.h
	g++ -c MainFunction.cpp

clean:
	rm -f *.o osc_test
