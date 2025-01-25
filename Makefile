# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 19:56:41 by yel-haya          #+#    #+#              #
#    Updated: 2025/01/22 17:33:42 by yel-haya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
CFLAGS =
LIB = libft/libft.a
PRI = printf/libftprintf.a
MLXFLAGS = -lmlx -framework OpenGl -framework AppKit
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c map_parsing.c map_parsing2.c placing_images.c movment.c map_parsing3.c
SRCB = bonusfile/so_long_bonus.c bonusfile/get_next_line_bonus/get_next_line_bonus.c \
       bonusfile/get_next_line_bonus/get_next_line_utils_bonus.c bonusfile/map_parsing_bonus.c \
       bonusfile/map_parsing2_bonus.c bonusfile/placing_images_bonus.c \
       bonusfile/movment_bonus.c bonusfile/map_parsing3_bonus.c
libs = ./libft/libft.a printf/libftprintf.a

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)


$(NAME): $(OBJ) $(libs)
	$(CC) $(OBJ) $(MLXFLAGS) -o $(NAME) $(LIB) $(PRI)

$(BONUS_NAME): $(OBJB) $(libs)
	$(CC) $(OBJB) $(MLXFLAGS) -o $(BONUS_NAME) $(LIB) $(PRI)

%_bonus.o: %_bonus.c bonusfile/so_long_bonus.h bonusfile/get_next_line_bonus/get_next_line_bonus.h libft/libft.h printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c so_long.h ./get_next_line/get_next_line.h libft/libft.h printf/ft_printf.h ./so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(BONUS_NAME)

$(libs):
	@make -C libft
	@make -C printf

clean:
	@make clean -C libft
	@make clean -C printf
	rm -rf $(OBJ) $(OBJB)

fclean: clean
	@make fclean -C libft
	@make fclean -C printf
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean all fclean re