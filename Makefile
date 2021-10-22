#targets
main: main.o unindent.o indent.o
	g++ -Wall -o main main.o unindent.o indent.o

main.o: main.cpp unindent.h indent.h
	g++ -Wall -c main.cpp

unindent.o: unindent.cpp unindent.h
	g++ -Wall -c unindent.cpp

indent.o: indent.cpp indent.h
	g++ -Wall -c indent.cpp

clean:
	rm -f *o a.out main
