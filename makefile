.PHONY: all clean fclean re

OS := $(shell uname -s)
CC := gcc
FLAGS := -Wall -Wextra -Werror
NAME := yshawn.filler

DIR_VIS := visualization
DIR_RES := resources
NAME_VIS := yshawn.visualization

H := include/filler.h
DIR_SRC := src
SRC := main solver record_data extra extra_2
SRC := $(addsuffix .c, $(SRC))

DIR_LIB := lib
LIB := libft.a

SRCS_1 = $(addprefix $(DIR_SRC)/,$(SRC))
SRCS_2 = $(addprefix $(DIR_LIB)/,$(LIB))

ifeq ($(OS), Linux)
all: $(NAME)
$(NAME): $(SRCS_1) $(H)
	@make -C $(DIR_LIB)
	@$(CC) $(FLAGS) $(SRCS_1) $(SRCS_2) -o $(NAME)
	@make -C $(DIR_VIS)
	@cp $(DIR_VIS)/$(NAME_VIS) $(DIR_RES)/$(NAME_VIS)
	@cp $(NAME) $(DIR_RES)/$(NAME)
else ifeq ($(OS), Darwin)
all:
	@echo "don't forget to add instructions here"
endif
vis:
	@make -C $(DIR_VIS)
	@cp $(DIR_VIS)/$(NAME_VIS) $(DIR_RES)/$(NAME_VIS)
clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(DIR_RES)/filler.trace
fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(DIR_RES)/$(NAME_VIS)
	@rm -f $(DIR_RES)/$(NAME)
	@rm -f $(NAME)
re: fclean all
