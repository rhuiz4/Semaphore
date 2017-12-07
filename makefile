all: sem.c sem.h
	gcc -o semaphore sem.c sem.h

run: all
	./semaphore -c 3
	./semaphore -v 3
	./semaphore -r 3
	./semaphore -v 3
	./semaphore -c 4
	./semaphore -v 4
	./semaphore -r 4

clean:
	rm sadshell
	rm *~
	rm *.o
