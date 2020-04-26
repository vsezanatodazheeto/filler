.PHONY: all clean fclean re

OS := $(shell uname -s)
CC := gcc
FLAGS := -Wall -Wextra -Werror
NAME := yshawn.visualization

DIR_H := include
H := vis_filler vis_sdl
H := $(addprefix $(DIR_H)/, $(addsuffix .h, $(H)))

DIR_SRC := src
DIR_SRC_1 := $(addprefix $(DIR_SRC)/, src_vis_filler)
DIR_SRC_2 := $(addprefix $(DIR_SRC)/, src_vis_sdl)
SRC_1 := main new_struct record_data extra extra_2
SRC_2 := main init key draw rect extra

DIR_LIB = ../lib
LIB := libft.a
LIB := $(addprefix $(DIR_LIB)/, $(LIB))

SRCS_1 := $(addprefix $(DIR_SRC_1)/, $(addsuffix .c, $(SRC_1)))
SRCS_2 := $(addprefix $(DIR_SRC_2)/, $(addsuffix .c, $(SRC_2)))

ifeq ($(OS), Linux)

FRAMEWORKS  := -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

all: $(NAME)
$(NAME): $(SRCS_1) $(SRCS_2) $(H)
	@make -C $(DIR_LIB)
	@$(CC) $(FLAGS) $(SRCS_1) $(SRCS_2) $(LIB) $(FRAMEWORKS) -o $(NAME)

else ifeq ($(OS), Darwin)

SDL_INCS :=  -I./frameworks/SDL2.framework/Versions/A/Headers \
		     -I./frameworks/SDL2_image.framework/Versions/A/Headers \
			 -I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
			 -I./frameworks/SDL2_mixer.framework/Versions/A/Headers 
FRAMEWORKS  := 	-F./frameworks \
				-rpath ./frameworks \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image -framework SDL2_mixer
	@echo "MAC INSTRUCTIONS"
all: $(NAME)
	@echo "don't forget to add instructions here in makefile"
	# @$(CC) $(SRCS_1) $(SRCS_2) $(SRCS_3) -I $(HEADER) $(SDL_INCS) $(FRAMEWORKS) -o $(NAME)
endif
clean:
	@make clean -C $(DIR_LIB)
fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME)
re: fclean all
