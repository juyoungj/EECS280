proj4.exe: LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o project4.o
	g++ -Wall LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o project4.o -o proj4.exe

project4.o: project4.cpp
	g++ -Wall -c project4.cpp -o project4.o

LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o

SortedListClass.o: SortedListClass.cpp SortedListClass.h
	g++ -Wall -c SortedListClass.cpp -o SortedListClass.o

FIFOQueueClass.o: FIFOQueueClass.cpp FIFOQueueClass.h
	g++ -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o

LIFOStackClass.o: LIFOStackClass.cpp LIFOStackClass.h
	g++ -Wall -c LIFOStackClass.cpp -o LIFOStackClass.o

clean:
	rm -rf project4.o LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o proj4.exe