# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 10:03:51 by jergashe          #+#    #+#              #
#    Updated: 2023/01/16 08:35:20 by jergashe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
RM = rm -rf
CFLAGS = -g
# -Wall -Wextra -Werror
LIBFT = libft_42/libft.a
GET_NEXT_LINE = get_next_line_42/get_next_line.a

SRCS = src/pipex.c	\
		src/check_args.c	\
		src/open_file.c	\
		src/execute.c	\
		src/get_path.c	\
		src/errors.c	\
		src/utils.c	\
		src/pipex_bonus.c	\
		src/here_doc.c	\
		src/main.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(GET_NEXT_LINE) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GET_NEXT_LINE)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	git submodule update --init --recursive --remote
	make -C ./libft_42

$(GET_NEXT_LINE):
	make -C ./get_next_line_42

clean:
	$(RM) $(OBJS)
	make clean -C ./libft_42
	make clean -C ./get_next_line_42

fclean:
	$(RM) $(OBJS) $(NAME)
	make fclean -C ./libft_42
	make fclean -C ./get_next_line_42

re: fclean all

.PHONY: all clean fclean re
