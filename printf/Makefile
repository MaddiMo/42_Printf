# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonclus <mmonclus@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 15:56:00 by mmonclus          #+#    #+#              #
#    Updated: 2023/01/27 16:24:25 by mmonclus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

SRCS	= 	ft_printf.c		\
			ft_further.c	
			
OBJS = $(SRCS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)

	@ar -rcs $(NAME) $(OBJS)
	@echo "Library created"
	
$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $^
	
clean:
	@rm -rf $(OBJS) clean
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME) 
	@echo "Library removed"

re: fclean all

.PHONY:		all clean fclean re
