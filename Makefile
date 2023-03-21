# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 01:12:01 by sel-jama          #+#    #+#              #
#    Updated: 2023/03/17 11:12:24 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex.c utils.c path.c children.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

all: ${NAME}

${NAME} : ${OBJS}
	@make -C libft/
	${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME} -fsanitize=address

clean :
	@rm -f ${OBJS}
	@make clean -C libft/

fclean : clean
	@rm -f ${NAME}
	@make fclean -C libft/

re: fclean all