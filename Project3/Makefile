proj3.exe: printMenu.o printColorMenu.o ColorImageClass.o RectangleClass.o ColorClass.o RowColumnClass.o AnnotatePattern.o proj3.o
	g++ -Wall printMenu.o printColorMenu.o ColorImageClass.o RectangleClass.o ColorClass.o RowColumnClass.o AnnotatePattern.o proj3.o -o proj3.exe

proj3.o: proj3.cpp
	g++ -Wall -c proj3.cpp -o proj3.o

printMenu.o: printMenu.cpp printMenu.h
	g++ -Wall -c printMenu.cpp -o printMenu.o

printColorMenu.o: printColorMenu.cpp printColorMenu.h
	g++ -Wall -c printColorMenu.cpp -o printColorMenu.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h
	g++ -Wall -c ColorImageClass.cpp -o ColorImageClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h
	g++ -Wall -c RectangleClass.cpp -o RectangleClass.o

ColorClass.o: ColorClass.cpp ColorClass.h
	g++ -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	g++ -Wall -c RowColumnClass.cpp -o RowColumnClass.o

AnnotatePattern.o: AnnotatePattern.cpp AnnotatePattern.h
	g++ -Wall -c AnnotatePattern.cpp -o AnnotatePattern.o

clean:
	rm -rf proj3.o printMenu.o printColorMenu.o ColorImageClass.o RectangleClass.o ColorClass.o RowColumnClass.o AnnotatePattern.o proj3.exe
