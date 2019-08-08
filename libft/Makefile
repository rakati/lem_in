# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 15:42:01 by nouhaddo          #+#    #+#              #
#    Updated: 2019/07/28 16:17:10 by nouhaddo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c *.c *.h
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean :
	/bin/rm -rf *.o *.gch

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all
