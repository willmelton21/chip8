objects = main.o chip8.o screen.o
CFLAGS = -Ivendor/SDL/include
LDFLAGS = vendor/SDL/build/libSDL3.a -ldl -lpthread -lm

c8 : $(objects)
	cc -o c8 $(objects) $(LDFLAGS)

main.o : chip8.h screen.h
chip8.o : chip8.h
screen.o : screen.h 

.PHONY : clean
clean :
	rm -f c8 $(objects)
