# Teenie

Another project for experiementing ui library

**Dependencies**:

- SDL2
- SDL_Image
- pkg-config

## Start guide

```console
$ make -B && ./_teenie.debug
```

Day 1:

- **application.{h|cpp}:** for running the main game
- **main.cpp:** wrapper for the game
- **graphics.{h|cpp}:** for creating renderer/window, get image from file path and drawing screen
- **input.{h|cpp}:** handling keypress, keyrelease and keyheld
- **./ultilities/\*.{h|cpp}:** handling SDL ERROR, and converts color code from hex to rgba and rgba to hex
- **./tiles/\*.{h.cpp}:** only texture loading for now, but I may extract the texture component to load entities as well
- **./assets/textures/\*.png:** only cursor image and tile image for now
