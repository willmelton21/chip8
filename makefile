objects = main.o chip8.o

c8 : $(objects)
	cc -o c8 $(objects)

main.o : chip8.h
chip8.o : chip8.h

.PHONY : clean
clean :
	rm c8 $(objects)
