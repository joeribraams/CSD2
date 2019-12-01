MainFunction: InstrumentInheritance.o MainFunction.o
	g++ -o test InstrumentInheritance.o MainFunction.o

InstrumentClasses.o: InstrumentInheritance.cpp InstrumentInheritance.h
	g++ -c InstrumentInheritance.cpp

MainFunction.o: MainFunction.cpp InstrumentInheritance.h
	g++ -c MainFunction.cpp

clean:
	rm -f *.o osc_test
