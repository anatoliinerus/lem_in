# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anerus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 17:27:54 by anerus            #+#    #+#              #
#    Updated: 2019/04/17 15:14:38 by anerus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra -g

SRC = src/main.c src/valid.c src/algorithm.c

OBJ = $(SRC:%.c=%.o) 

all: $(NAME)

%.o:%.c
	@gcc -c $(FLAGS) $< -o $@

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(OBJ) libft/libft.a -o $(NAME)

clean: 
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all


# NAME = lem-in

# FLAGS = -Werror -Wextra -Wall -fsanitize=address -g


# all: $(NAME)

# $(NAME):
# 	@make -C libft
# 	@cp ./libft/libft.a ./
# 	@gcc $(FLAGS) src/*.c -Iinclude -lft -L./ -o $(NAME)

# clean:
# 	@rm -rf *.o
# 	@make clean -C libft

# fclean: clean
# 	@rm -rf $(NAME) libft.a
# 	@make fclean -C libft

# re: fclean all