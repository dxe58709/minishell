# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: N <nsakanou@student.42tokyo.jp>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:02:17 by N                 #+#    #+#              #
#    Updated: 2023/12/11 17:09:30 by N                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# Libft+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBDIR)
RM = rm -f

SRCS =	builtin/exit.c \
	builtin/unset.c \
	builtin/env.c \
	builtin/pwd.c \
	builtin/export.c \
	builtin/cd.c \
	builtin/echo.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR) all

clean:
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re