# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabel <aabel@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 11:37:21 by aabel             #+#    #+#              #
#    Updated: 2023/08/22 11:43:39 by aabel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/main.c \
		src/parsing.c \

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:%.c=%.o)

cc = gcc

all: $(NAME)

$(NAME): $(OBJ)
				@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all