.PHONY: all clean fclean re

OS := $(shell uname -s)
CC := gcc
FLAGS := -Wall -Wextra -Werror
NAME := yshawn.filler

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
else ifeq ($(NAME), $(MAC))
all:
	@echo "don't forget to add instructions here"
	# @$(CC) $(FLAGS) $(SRCS_1) $(SRCS_2) $(SRCS_3) $(SRCS_4) $(SRCS_5) -I $(HEADER) -o $(NAME)
endif
clean:
	@make clean -C $(DIR_LIB)
fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME)
re: fclean all