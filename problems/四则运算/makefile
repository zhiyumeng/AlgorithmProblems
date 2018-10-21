demo2:main.o  Computer.o
	g++ -o demo2 main.o Computer.o -std=c++11
main.o:main.cpp Stack.h Computer.h
	g++ -c main.cpp Stack.h Computer.h -std=c++11
Computer.o:Computer.cpp Computer.h Stack.h
	g++ -c Computer.cpp -std=c++11
clean:
	rm -f *.o main *.gch