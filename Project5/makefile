proj5.exe: proj5.o random.o EventClass.o Customer.o SimulationClass.o
	g++ proj5.o random.o EventClass.o Customer.o SimulationClass.o -o proj5.exe

proj5.o: proj5.cpp LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h constants.h
	g++ -c proj5.cpp -o proj5.o

random.o: random.cpp random.h
	g++ -c random.cpp -o random.o

EventClass.o: EventClass.cpp EventClass.h
	g++ -c EventClass.cpp -o EventClass.o

Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp -o Customer.o

SimulationClass.o: SimulationClass.cpp SimulationClass.h
	g++ -c SimulationClass.cpp -o SimulationClass.o

clean:
	rm -rf proj5.exe proj5.o random.o EventClass.o Customer.o SimulationClass.o