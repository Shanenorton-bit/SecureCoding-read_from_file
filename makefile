all: read

read:
	gcc -o read read.c

clean:
	rm -f *.o read
