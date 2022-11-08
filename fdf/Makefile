# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greita <greita@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 08:59:10 by greita            #+#    #+#              #
#    Updated: 2022/11/08 19:26:39 by greita           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		fdf

NAME_B =	fdf_bonus

SRC =		src/fdf.c	\
			src/drawline.c	\
			src/parser.c	\
			src/parser_utils.c	\
			src/draw.c \
			src/draw_utils.c \
			src/keyhook.c \
			src/keyhook_utils.c

OBJ = 		$(SRC:.c=.o)

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

FRAMEWORK =	-framework OpenGL -framework AppKit

D_FILES =	$(SRC:.c=.d)

%.o :		%.c
	$(CC) $(FLAGS) -c $< -o $@ -MMD

all :		$(NAME)

bonus:		$(NAME_B)

-include	$(D_FILES) $(D_FILES_B)

$(NAME) :	$(OBJ)
	make all -C ./libft
	make all -C ./mlx
	$(CC) $(FLAGS) $(OBJ) $(FRAMEWORK) ./libft/libft.a ./mlx/libmlx.a -o $(NAME)

$(NAME_B) :	$(OBJ)
	make all -C ./libft
	make all -C ./mlx
	$(CC) $(FLAGS) $(OBJ) $(FRAMEWORK) ./libft/libft.a ./mlx/libmlx.a -o $(NAME_B)

clean :
	make clean -C ./libft
	make clean -C ./mlx
	rm -f $(OBJ) $(OBJ_B) $(D_FILES)

fclean :	clean
	rm -f ./libft/libft.a
	rm -f $(NAME)
	rm -f $(NAME_B)

re :		fclean all

rebonus :	fclean bonus

.PHONY :	all clean fclean re rebonus bonus
