CC = g++

CFLAGS = -c -Wall

all: run

run:
	$(CC) main.cpp mocker/mocker.cpp tester/tester.cpp -o run

.PHONY : clean
clean:
	rm -rf *.o run
