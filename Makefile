build:
	gcc -o game ./src/main.c ./src/game.c ./src/resources.c ./src/uielement.c ./src/background.c ./src/main_menu.c ./src/play.c ./src/settings.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows