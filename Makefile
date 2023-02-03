# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 10:03:51 by jergashe          #+#    #+#              #
#    Updated: 2023/02/01 17:13:13 by jergashe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft_42/libft.a

SRCS = src/pipex.c	\
		src/check_args.c	\
		src/open_file.c	\
		src/execute.c	\
		src/get_path.c	\
		src/errors.c	\
		src/utils.c	\

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = src/pipex_bonus.c	\
			src/here_doc.c	\
			src/check_args.c	\
			src/open_file.c	\
			src/execute.c	\
			src/get_path.c	\
			src/errors.c	\
			src/utils.c	\

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	#  git submodule update --init --recursive --remote
	make -C ./libft_42


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJ) $(LIBFT)

clean:
	$(RM) $(OBJS) $(BONUS_OBJ)
	make clean -C ./libft_42

fclean:
	$(RM) $(OBJS) $(NAME) $(BONUS_OBJ) $(NAME_BONUS)
	make fclean -C ./libft_42

re: fclean all

.PHONY: all clean fclean re
