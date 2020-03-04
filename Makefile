.PHONY: all clean fclean re

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = yshawn.filler
HEADER = include/filler.h
LIB = a_libft/
PRINTLIB = a_printf/

DIR_S_1 = ./
DIR_S_2 = src
DIR_S_3 = ./a_printf/
DIR_S_4 = ./a_libft/
DIR_S_5 = ./a_gnl/

SOURCES_1 = main.c
SOURCES_2 = extra.c extra_2.c record_data.c solver.c
SOURCES_3 = libftprintf.a
SOURCES_4 = libft.a
SOURCES_5 = get_next_line.c

SRCS_1 = $(addprefix $(DIR_S_1)/,$(SOURCES_1))
SRCS_2 = $(addprefix $(DIR_S_2)/,$(SOURCES_2))
SRCS_3 = $(addprefix $(DIR_S_3)/,$(SOURCES_3))
SRCS_4 = $(addprefix $(DIR_S_4)/,$(SOURCES_4))
SRCS_5 = $(addprefix $(DIR_S_5)/,$(SOURCES_5))
all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@make -C $(PRINTLIB)
	@$(CC) $(FLAGS) $(SRCS_1) $(SRCS_2) $(SRCS_3) $(SRCS_4) $(SRCS_5) -I $(HEADER) -o $(NAME)
	@chmod 777 $(NAME)
clean:
	@make clean -C $(LIB)
	@make clean -C $(PRINTLIB)
	@rm -f filler.trace
fclean: clean
	@make fclean -C $(LIB)
	@make fclean -C $(PRINTLIB)
	@rm -f $(NAME)
re: fclean all
