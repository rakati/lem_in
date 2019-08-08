# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makerfile                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/01 14:40:46 by nouhaddo          #+#    #+#              #
#    Updated: 2019/08/01 17:06:53 by nouhaddo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c\
	  read_rooms.c\
	  read_connections.c\
	  hash_functions.c\
	  ft_tools.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBFT_OBJ = ./libft/*.o

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAG) -c $(SRC)
	gcc $(OBJ) $(LIBFT_OBJ) -o $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJ) *.h.gch

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all
