CC=g++
CFLAGS=-g --std=c++11

lab2.exe: main.o util.o
	$(CC) -o lab2.exe $(CFLAGS) main.cpp util.cpp 
main.o: main.cpp util.h
	$(CC) $(CFLAGS) -c main.cpp

util.o: util.cpp util.h
	$(CC) $(CFLAGS) -c util.cpp

test: lab2.exe
        ./lab2.exe -tc="$(TC)" -sc="$(SC)"

clean:
	rm util.o main.o lab2.exe
