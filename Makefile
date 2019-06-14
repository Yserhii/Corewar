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

CORE :=				corewar
ASM := asm

SRC_DIR_VM :=		./src/vm/
SRC_DIR_ASM := 		./src/asm/
OBJ_DIR_VM :=		./obj_vm/
OBJ_DIR_ASM :=		./obj_asm/
INC_DIR_VM :=		./inc_vm/
INC_DIR_ASM :=		./inc_asm/
LIB_DIR :=			./lib/

# project source files

SRC_VM :=			main.c read_valid_av.c read_valid_bot.c\
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

SRC_ASM := 			main_asm.c check.c ft_write.c name_comment.c parse_code.c \
					tokens.c hex_converter.c live.c hex_code.c add.c aff.c \
					fork.c ld.c st.c sub.c zjmp.c sti.c ldi.c ft_and_or.c options.c\
					fnc.c valid_code.c

# project object files

OBJ_VM =				$(addprefix $(OBJ_DIR_VM), $(SRC_VM:.c=.o))
OBJ_ASM =				$(addprefix $(OBJ_DIR_ASM), $(SRC_ASM:.c=.o))

# libraries

LIBFT =				$(LIBFT_DIR)libft.a
LIBFT_DIR :=		$(LIB_DIR)libft/
LIBFT_INC :=		$(LIBFT_DIR)includes/

LIBRARIES_VM = -lncurses -lft -L$(LIBFT_DIR)
LIBRARIES_ASM = -lft -L$(LIBFT_DIR)

# compilation flags

CC_FLAGS :=			-Wall -Wextra -Werror

# add linking flags for different libraries

LINK_FLAGS_VM :=		$(LIBRARIES_VM)
LINK_FLAGS_ASM :=		$(LIBRARIES_ASM)

# header flags

HEADER_FLAGS_VM :=		-I $(INC_DIR_VM) -I $(LIBFT_INC)
HEADER_FLAGS_ASM :=		-I $(INC_DIR_ASM) -I $(LIBFT_INC)

# change compiler for different systems

CC :=				clang

# rules

all: $(CORE) $(ASM)

$(CORE): $(LIBFT) $(OBJ_VM)
		$(CC) $(OBJ_VM) $(LINK_FLAGS_VM) -o $(CORE)

$(OBJ_VM): | $(OBJ_DIR_VM)

$(OBJ_DIR_VM):
	mkdir $(OBJ_DIR_VM)
	mkdir ./obj_vm/op
	mkdir ./obj_vm/visual

$(OBJ_DIR_VM)%.o: %.c
		$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS_VM)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(ASM): $(OBJ_ASM)
		$(CC) $(OBJ_ASM) $(LINK_FLAGS_ASM) -o $(ASM)

$(OBJ_ASM): | $(OBJ_DIR_ASM)

$(OBJ_DIR_ASM):
	mkdir $(OBJ_DIR_ASM)

$(OBJ_DIR_ASM)%.o: %.c
		$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS_ASM)

clean:
		rm -f $(OBJ_VM)
		rm -f $(OBJ_ASM)
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -f $(CORE)
		rm -f $(ASM)
		rm -rf $(OBJ_DIR_VM)
		rm -rf $(OBJ_DIR_ASM)
		make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR_VM)
vpath %.c $(SRC_DIR_ASM)

.PHONY: all clean fclean re
