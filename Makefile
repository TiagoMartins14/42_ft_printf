# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 09:35:34 by patatoss          #+#    #+#              #
#    Updated: 2023/05/11 09:51:03 by patatoss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC		=	${wildcard *.c} ${wildcard libft/*.c}

OBJ		=	${SRC:.c=.o}

RM = rm -f

AR = ar -rc


%.o: %.c 
	@${CC} ${FLAGS} -c $< -I . -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	@make clean -C libft
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C libft
	@$(RM) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
