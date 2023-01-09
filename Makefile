# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 10:03:51 by jergashe          #+#    #+#              #
#    Updated: 2023/01/09 10:06:04 by jergashe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
RM = rm -rf
CFLAGS = -g
# -Wall -Wextra -Werror
LIBFT = libft_42/libft.a

SRCS = src/pipex.c	\
		src/check_args.c	\
		src/open_file.c	\
		src/execute.c	\
		src/get_path.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	git submodule update --init --recursive --remote
	make -C ./libft_42

clean:
	$(RM) $(OBJS)
	make clean -C ./libft_42

fclean:
	$(RM) $(OBJS) $(NAME)
	make fclean -C ./libft_42

re: fclean all

.PHONY: all clean fclean re
