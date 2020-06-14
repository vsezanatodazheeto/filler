# SHELL
OS = $(shell uname -s)

# COLORS
BLUE = "\e[38;5;69m"
GREEN = "\e[38;5;48m"
EOC = "\e[0m"

# COMPILER
CC = gcc
FLAGS = -Wall -Wextra -Werror -Wunused

# VISUALISATION
NAME = vis

# DESTINATION DIRECTORY
DIR_RES = ../resources

# HEADERS
DIR_H = include

H = vis_filler vis_sdl
H := $(addprefix $(DIR_H)/, $(addsuffix .h, $(H)))

# SOURCES
DIR_SRC = src

DIR_SRC_FILLER = $(addprefix $(DIR_SRC)/, src_vis_filler)
DIR_SRC_SDL = $(addprefix $(DIR_SRC)/, src_vis_sdl)

SRC_FILLER = main new_struct record_data extra extra_2
SRC_SDL = main init key draw rect extra

# LIB (LIBFT, GET_NEXT_LINE, PRINTF)
DIR_LIB = ../lib
LIB := lib.a
LIB_RULE = $(addsuffix .lib, $(DIR_LIB)/)

# FILE PATH TO LIB, VISUALIZATION SRC/OBJ FILES
SRCS_FILLER = $(addprefix $(DIR_SRC_FILLER)/, $(addsuffix .c, $(SRC_FILLER)))
SRCS_SDL = $(addprefix $(DIR_SRC_SDL)/, $(addsuffix .c, $(SRC_SDL)))
LIBS = $(addprefix $(DIR_LIB)/, $(LIB))

ifeq ($(OS), Linux)

	SDL_INCS :=
	FRAMEWORKS := \
		-lSDL2 \
		-lSDL2_image \
		-lSDL2_ttf \
		-lSDL2_mixer

else ifeq ($(OS), Darwin)

	SDL_INCS := \
		-I./frameworks/SDL2.framework/Versions/A/Headers \
		-I./frameworks/SDL2_image.framework/Versions/A/Headers \
		-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
		-I./frameworks/SDL2_mixer.framework/Versions/A/Headers
	FRAMEWORKS := \
		-F./frameworks \
		-rpath ../visualization/frameworks \
		-framework SDL2 \
		-framework SDL2_ttf \
		-framework SDL2_image \
		-framework SDL2_mixer

endif

all: $(LIB_RULE) $(NAME)

%.lib:
	@$(MAKE) -sC $(DIR_LIB)

$(NAME): $(SRCS_FILLER) $(SRCS_SDL) $(H)
ifeq ($(OS), Linux)
	@$(CC) $(CFLAGS) $(SRCS_FILLER) $(SRCS_SDL) $(LIBS) -I, $(H) $(SDL_INCS) $(FRAMEWORKS) -o $(NAME)
else ifeq ($(OS), Darwin)
	@$(CC) $(CFLAGS) $(SRCS_FILLER) $(SRCS_SDL) $(LIBS) $(SDL_INCS) $(FRAMEWORKS) -o $(NAME)
endif
	@echo $(BLUE)"VIS COMPILED"$(EOC)
	cp $(NAME) $(DIR_RES)/$(NAME)
	@echo $(GREEN)"VIS COPIED TO RESOURCES DIRECTORY"$(EOC)

clean:
	@$(MAKE) -sC $(DIR_LIB) clean

fclean: clean
	@$(MAKE) -sC $(DIR_LIB) fclean
	@rm -f $(NAME)
	@rm -f $(DIR_RES)/$(NAME)

re: fclean all

.PHONY: all clean fclean re