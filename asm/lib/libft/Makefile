# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 17:01:12 by yhliboch          #+#    #+#              #
#    Updated: 2018/11/26 15:56:57 by yhliboch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putnbr.c ft_putchar.c ft_putstr.c ft_isalpha.c ft_atoi.c ft_bzero.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c  \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_strcmp.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_strrchr.c \
		ft_strdup.c ft_strcpy.c ft_strncpy.c  ft_strcat.c ft_strncat.c  \
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strlcat.c\
		ft_strclr.c ft_striter.c ft_striteri.c  ft_strmap.c ft_strmapi.c \
		ft_strequ.c  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_strsplit.c ft_itoa.c  ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstmap.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		get_next_line.c ft_lstaddend.c check.c ft_printf.c d_printf.c \
		u_printf.c ft_itoa_u.c o_printf.c ft_itoa_base.c ft_itoa_x.c x_printf.c \
		scp_printf.c change.c f_printf.c ft_itoa_f.c round.c ft_itoa_d.c \
		p_printf.c ft_num_words.c ft_strndup.c

INK = includes/

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)

%.o: %.c
		@clang -I$(INK) $(FLAG) -o $@ -c $<

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
