# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yserhii <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 11:29:13 by yserhii           #+#    #+#              #
#    Updated: 2018/12/23 11:29:17 by yserhii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME :=				corewar
#NAME_V :=			vis

# project directories

SRC_DIR :=			./src/
OBJ_DIR :=			./obj/
INC_DIR :=			./inc/
LIB_DIR :=			./lib/


#SRC_DIR_V :=			./src_v/
#OBJ_DIR_V :=			./obj_v/
#INC_DIR_V :=			./inc_v/

# project source files

SRC =				main.c read_valid_av.c read_valid_bot.c\
					read_valid_flags.c initialization_map.c\
					battle.c output.c vm_exit.c checks_bot_args.c\
					op/vm_add.c op/vm_aff.c op/vm_and.c\
					op/vm_fork.c op/vm_ld.c op/vm_ldi.c\
					op/vm_lfork.c op/vm_live.c op/vm_lld.c\
					op/vm_lldi.c op/vm_or.c op/vm_st.c\
					op/vm_sti.c op/vm_sub.c op/vm_xor.c\
					op/vm_zjmp.c op/op_make_and_add_func.c\
					op/op_make_args.c\
					visual/visual.c visual/start_menu.c

#SRC_V =				ft_visual.c ft_visual_main.c finish.c

# project object files

OBJ =				$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#OBJ_V =				$(addprefix $(OBJ_DIR_V), $(SRC_V:.c=.o))

# libraries

LIBFT =				$(LIBFT_DIR)libft.a
LIBFT_DIR :=		$(LIB_DIR)libft/
LIBFT_INC :=		$(LIBFT_DIR)includes/

LIBRARIES = -lncurses -lft -L$(LIBFT_DIR)
#LIBRARIES_V = -lmlx -lft -L$(LIBFT_DIR) -framework OpenGL -framework AppKit

# compilation flags

CC_FLAGS :=			-Wall -Wextra -Werror

# add linking flags for different libraries

LINK_FLAGS :=		$(LIBRARIES)
LINK_FLAGS_V :=		$(LIBRARIES_V)

# header flags

HEADER_FLAGS :=		-I $(INC_DIR) -I $(LIBFT_INC)

#HEADER_FLAGS_V :=		-I $(INC_DIR_V) -I $(LIBFT_INC)

# change compiler for different systems

CC :=				clang

# rules

all: $(NAME) #$(NAME_V)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	mkdir ./obj/op
	mkdir ./obj/visual

$(OBJ_DIR)%.o: %.c
		$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		make -C $(LIBFT_DIR)

#$(NAME_V): $(OBJ_V)
#		$(CC) $(OBJ_V) $(LINK_FLAGS_V) -o $(NAME_V)

#$(OBJ_V): | $(OBJ_DIR_V)

#$(OBJ_DIR_V):
#	mkdir $(OBJ_DIR_V)

#$(OBJ_DIR_V)%.o: %.c
#		$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS_V)

clean:
		rm -f $(OBJ)
#		rm -f $(OBJ_V)
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -f $(NAME)
#		rm -f $(NAME_V)
		rm -rf $(OBJ_DIR)
#		rm -rf $(OBJ_DIR_V)
		make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
#vpath %.c $(SRC_DIR_V)

.PHONY: all clean fclean re
