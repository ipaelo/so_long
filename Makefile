# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 12:24:15 by itorres-          #+#    #+#              #
#    Updated: 2022/09/27 14:09:53 by itorres-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror -g
RM			=	rm -f

LIBS		=	./MLX42/libmlx42.a ./libft/libft.a  
OPENGL		=	-I include -lglfw -L "/Users/itorres-/.brew/opt/glfw/lib/"
FRAMEWORK	=	-framework Cocoa -framework OpenGL -framework IOKit
	
SRCS		=	so_long.c		\
				finish_end.c	\
				checks.c		\
				checks_1.c		\
				maps.c			\
				moves.c	
				

SRCS_BONUS	=	so_long_bonus.c		\
				finish_end_bonus.c	\
				checks_bonus.c		\
				checks_1_bonus.c	\
				maps_bonus.c		\
				moves_bonus.c	

OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

%.o		:	%.c
		gcc $(FLAGS) -c $^ -I ./ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make all -C ./libft
	make all -C ./MLX42
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(OPENGL) $(FRAMEWORK) -o $(NAME) 

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make all -C ./libft
	make all -C ./MLX42
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(LIBS) $(OPENGL) $(FRAMEWORK) -o $(NAME_BONUS)
	
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C ./libft
	make clean -C ./MLX42

fclean: clean
	make fclean -C ./libft
	make fclean -C ./MLX42
	$(RM) $(NAME) $(NAME_BONUS)

re:		 fclean all

rebonus: fclean bonus

.PHONY:  all, clean, fclean, re, bonus, rebonus
