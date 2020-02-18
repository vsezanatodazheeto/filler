# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 19:41:13 by yshawn            #+#    #+#              #
#    Updated: 2020/02/18 08:52:16 by yshawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# FLAGS = -Wall -Wextra -Werror
NAME = a.out

DIR_S_1 = ./
DIR_S_2 = src
DIR_S_3 = a_printf

HEADER = include/filler.h

SOURCES_1 = main.c
SOURCES_2 = extra.c record_data.c
SOURCES_3 = libftprintf.a

SRCS_1 = $(addprefix $(DIR_S_1)/,$(SOURCES_1))
SRCS_2 = $(addprefix $(DIR_S_2)/,$(SOURCES_2))
SRCS_3 = $(addprefix $(DIR_S_3)/,$(SOURCES_3))
all:
	@$(CC) $(SRCS_1) $(SRCS_2) $(SRCS_3) a_my_libft/*.c -I $(HEADER)
clean:
	@rm -f $(NAME)
	@rm -f filler.trace






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