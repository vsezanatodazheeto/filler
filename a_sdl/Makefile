# SDL_INCS = -I./frameworks/SDL2.framework/Versions/A/Headers \
# 		     -I./frameworks/SDL2_image.framework/Versions/A/Headers \
# 			 -I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
# 			 -I./frameworks/SDL2_mixer.framework/Versions/A/Headers 
# FRAMEWORKS  = -F./frameworks \
# 				-rpath ./frameworks \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image -framework SDL2_mixer

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = a.out
HEADER = include/filler_v.h

SOURCES_1 = main.c
SOURCES_2 = extra.c record_data.c new_struct.c sdl_init.c sdl_main.c
SOURCES_3 = libftprintf.a

DIR_S_1 = ./
DIR_S_2 = src
DIR_S_3 = ../a_printf

SRCS_1 = $(addprefix $(DIR_S_1)/,$(SOURCES_1))
SRCS_2 = $(addprefix $(DIR_S_2)/,$(SOURCES_2))
SRCS_3 = $(addprefix $(DIR_S_3)/,$(SOURCES_3))

all:
	@$(CC) $(SRCS_1) $(SRCS_2) $(SRCS_3) ../a_libft/*.c -lSDL2 -lSDL2_image -I $(HEADER)
clean:
	@rm -f $(NAME)
re: clean all

#@$(CC) $(SRCS_1) $(SRCS_2) $(SRCS_3) ../a_libft/*.c -I $(HEADER) $(SDL_INCS) $(FRAMEWORKS) -o $(NAME)