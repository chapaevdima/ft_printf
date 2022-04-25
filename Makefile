# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 17:06:55 by anatasha          #+#    #+#              #
#    Updated: 2021/12/15 19:51:57 by anatasha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c	ft_printf_utils.c	ft_printf_hex.c

HEADER	=	ft_printf.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

all		:	$(NAME)

$(NAME) :	$(OBJ) $(HEADER)
		ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean	:
		@rm -f $(OBJ)

fclean	:	clean
		@$(RM) $(NAME)

re		:	fclean all