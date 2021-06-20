# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 13:33:21 by cramdani          #+#    #+#              #
#    Updated: 2021/06/17 15:41:00 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	push_swap
CHECKER	=	checker

export CC		=	gcc
export CFLAGS	=	-Wall -Wextra -Werror 
export RM		=	rm -f
LIBFT_PATH	= libft
HEADER	=	push_swap.h

OBJS	=	${SRCS:.c=.o}

SRCS 	= 	$(wildcard *.c)
SRCS	:= $(filter-out checker.c main.c, $(SRCS))

all		:	${NAME} ${CHECKER}

$(NAME) : ${OBJS} main.o
		@(cd $(LIBFT_PATH) && $(MAKE))
		cp ${LIBFT_PATH}/libft.a ./ 
		$(CC) -o $@ $(CFLAGS) $^ libft.a

$(CHECKER) : ${OBJS} checker.o 
		$(CC) -o $@ $(CFLAGS) $^ libft.a

%.o		:	%.c %.h
			$(CC)  $(GCC_FLAGS) -c  $< 

clean	:
		${RM} ${OBJS} main.o checker.o
		@cd ${LIBFT_PATH} && $(MAKE) fclean

fclean	:	clean
			${RM} ${NAME} ${CHECKER} libft.a

re		:	fclean all

.PHONY	:	all clean fclean re