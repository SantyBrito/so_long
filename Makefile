# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 15:53:19 by sbrito            #+#    #+#              #
#    Updated: 2024/04/12 21:20:54 by sbrito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c map_utils.c rendering.c errors.c \
			errors2.c movements.c textures.c \
			libft_tools/printf_funct.c \
			libft_tools/ft_printf.c \
			libft_tools/get_next_line.c \
			libft_tools/get_next_line_utils.c \

OBJC	=	so_long.o get_next_line.o get_next_line_utils.o \
			map_utils.o rendering.o errors.o printf_funct.o \
			ft_printf.o errors2.o movements.o textures.o

INC		=	so_long.h

NAME	=	so_long

FLAGS	=	-Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJC)
	make -C minilibx-linux
	cc $(FLAGS) $(OBJC) -o $(NAME) -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm

$(OBJC): $(SRCS)
	cc $(FLAGS) $(SRCS) -c

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

norminette: 
	norminette $(SRCS) so_long.h

valgrind:
	valgrind --leak-check=full ./so_long maps/map1.ber

re: fclean all