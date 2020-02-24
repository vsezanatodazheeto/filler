# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 19:41:13 by yshawn            #+#    #+#              #
#    Updated: 2020/02/24 02:12:41 by yshawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = a.out
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
clean:
	@make clean -C $(LIB)
	@make clean -C $(PRINTLIB)
	@rm -f filler.trace
fclean: clean
	@make fclean -C $(LIB)
	@make fclean -C $(PRINTLIB)
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

# CC = gcc
# NAME = libftprintf.a
# FLAGS = -Wall -Wextra -Werror -O2 -O3 -O1
# DIR_S = SRC
# DIR_O = OBJ
# HEADER = header.h
# SOURCES = ft_strlen.c ft_numlen.c ft_itoabasex.c ft_atoi.c ft_str_sym_cmp.c ft_bzero.c ft_strdup.c ft_strjoin.c ft_strdel.c \
# ft_clean_struct.c ft_clean_mult.c \
# ft_cast_size_di.c ft_cast_size_poxu.c ft_cast_size_float.c \
# ft_printf.c \
# parse_chr.c parse_str.c parse_per.c parse_bit.c parse_bcolor.c parse_bdollar.c parse_float.c parse_dipoxu.c \
# parse_num_spec.c parse_dipoxu_spec_cases.c parse_num.c \
# ld_util.c \
# parse_specifiers.c parse_output.c \
# parse_float_number.c parse_float_flag.c \
# record_chr.c record_str.c record_bit.c record_per.c record_float.c \
# ft_smbu.c long_m_str.c long_math.c ft_array_mantisa.c \
# is_specifers.c 
# SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
# OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
# all: $(NAME)
# $(DIR_O)/%.o: $(DIR_S)/%.c
# 	@mkdir -p $(DIR_O) 
# 	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<
# $(NAME): $(SRCS) $(OBJS)
# 	@ar rc $(NAME) $(OBJS)
# 	@ranlib $(NAME)
# clean:
# 	@rm -f $(OBJS)
# 	@rm -rf $(DIR_O)
# fclean: clean
# 	@rm -f $(NAME)
# re: fclean all