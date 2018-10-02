all : struct.c
	gcc -o struct struct.c

run : struct
	./struct
