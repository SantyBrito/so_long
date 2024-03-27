# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 15:53:19 by sbrito            #+#    #+#              #
#    Updated: 2024/03/27 19:51:17 by sbrito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c get_next_line.c get_next_line_utils.c

OBJC	=	so_long.o get_next_line.o get_next_line_utils.o

INC		=	so_long.h

NAME	=	so_long

FLAGS	=	-Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJC)
	make -C minilibx-linux
	cc $(FLAGS) $(OBJC) -o $(NAME) -Lminilibx-linux -lmlx_Linux -lXext -lX11

$(OBJC): $(SRCS)
	cc $(FLAGS) $(SRCS) -c

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

norminette: 
	norminette $(SRCS) so_long.h

valgrind:
	valgrind --leak-check=full ./so_long

re: fclean all