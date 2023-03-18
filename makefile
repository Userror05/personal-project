SRC = src/balle.cpp src/terrain.cpp src/jeu.cpp src/cellule.cpp src/gravite.cpp src/obstacle.cpp

FINAL_TARGET_SDL = golfnic_sdl




CC					= g++
LD 					= g++
LDFLAGS  			=
CPPFLAGS 			= -Wall -ggdb   #-O2   # pour optimiser
OBJ_DIR 			= obj
SRC_DIR 			= src
BIN_DIR 			= bin
INCLUDE_DIR			= -I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lGL


default: make_dir $(BIN_DIR)/$(FINAL_TARGET_SDL)



make_dir:
$(BIN_DIR)/$(FINAL_TARGET_SDL): $(SRCS_SDL:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SDL)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) $< -o $@



#docu: doc/pacman.doxy
	cd doc ; doxygen pacman.doxy

clean:

rm -rf $(OBJ_DIR) $(BIN_DIR)/$(FINAL_TARGET_SDL) doc/html