# SHELL
OS = $(shell uname -s)

# COLORS
BLUE = "\e[38;5;69m"
GREEN = "\e[38;5;48m"
EOC = "\e[0m"

# COMPILER
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunused

# FILLER
NAME = yshawn.filler

# VISUALISATION
DIR_VIS = visualization

NAME_VIS = vis

# DESTINATION DIRECTORY
DIR_RES = resources

# HEADER
H = include/filler.h

# SOURCES
DIR_SRC = src

SRC = main solver record_data extra extra_2
SRC := $(addsuffix .c, $(SRC))

# LIB (LIBFT, GET_NEXT_LINE, PRINTF)
DIR_LIB = lib
LIB = lib.a
LIB_RULE = $(addsuffix .lib, $(DIR_LIB)/)

# FILE PATH TO LIB, FILLER SRC/OBJ FILES
SRCS = $(addprefix $(DIR_SRC)/, $(SRC))
LIBS = $(addprefix $(DIR_LIB)/, $(LIB))

all: $(LIB_RULE) $(NAME)

%.lib:
	@$(MAKE) -sC $(DIR_LIB)

vis:
	@$(MAKE) -sC $(DIR_VIS)

$(NAME): $(SRCS) $(H)
ifeq ($(OS), Linux)
	@$(CC) $(CFLAGS) $(SRCS) -I, $(H) $(LIBS) -o $(NAME)
else ifeq ($(OS), Darwin)
	@$(CC) $(CFLAGS) $(SRCS) -I $(H) $(LIBS) -o $(NAME)
endif
	@echo $(BLUE)"YSHAWN.FILLER COMPILED"$(EOC)
	@cp $(NAME) $(DIR_RES)/$(NAME)
	@echo $(GREEN)"YSHAWN.FILLER COPIED TO RESOURCES DIRECTORY"$(EOC)

clean:
	@$(MAKE) -sC $(DIR_LIB) clean
	@$(MAKE) -sC $(DIR_VIS) clean
	@rm -f $(DIR_RES)/filler.trace

fclean: clean
	@$(MAKE) -sC $(DIR_LIB) fclean
	@$(MAKE) -sC $(DIR_VIS) fclean
	@rm -f $(DIR_RES)/$(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
