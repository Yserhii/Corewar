# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 14:31:12 by yhliboch          #+#    #+#              #
#    Updated: 2019/02/14 14:31:13 by yhliboch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := asm

SRC_DIR := ./src/
OBJ_DIR := ./obj/
LIB_DIR := ./lib/
INK_DIR := ./ink/

SRC := main.c check.c ft_write.c name_comment.c parse_code.c \
		tokens.c hex_converter.c live.c hex_code.c add.c aff.c \
		fork.c ld.c st.c sub.c zjmp.c sti.c ldi.c ft_and_or.c options.c\
		fnc.c valid_code.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INK := $(LIBFT_DIR)includes/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

FLAGS := -Wall -Wextra -Werror
LINK_FLAGS := $(LIBFT_FLAGS)
HEADER_FLAGS := -I $(INK_DIR) -I $(LIBFT_INK)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		@$(CC) $(FLAGS) -c $< -o $@ $(HEADER_FLAGS)

$(LIBFT):
		@make -C $(LIBFT_DIR)

clean:
		@rm -f $(OBJ)
		@make clean -C $(LIBFT_DIR)

fclean: clean
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
