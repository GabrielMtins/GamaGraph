CFILES="main.c core.c parser.c function.c hud.c"

INCLUDE="-I./bmp"

LINKER="-L./bmp"

CFLAGS="-lSDL2 -lSDL2_ttf -lbmp -lm"

gcc $CFILES $CFLAGS $INCLUDE $LINKER -o main
