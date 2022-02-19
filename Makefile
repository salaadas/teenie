CFLAGS=-Wall -Werror -pedantic `pkg-config --cflags sdl2 SDL2_image`
LIBS=`pkg-config --libs sdl2 SDL2_image` -lm
SRC=main.cpp application.cpp graphics.cpp input.cpp texture.cpp math/linalg.cpp ultilities/checkcode.cpp ultilities/color_converter.cpp tiles/tilegrid.cpp

debug:
	g++ $(CFLAGS) -o _teenie.debug $(SRC) $(LIBS)
