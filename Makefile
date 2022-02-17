CFLAGS=-Wall -Wextra -pedantic `pkg-config --cflags sdl2 SDL2_image`
LIBS=`pkg-config --libs sdl2 SDL2_image` -lm
SRC=main.cpp application.cpp graphics.cpp input.cpp ./tiles/*.cpp ./ultilities/*.cpp

debug:
	g++ $(CFLAGS) -o _experiment.debug $(SRC) $(LIBS)