# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 14:09:43 by nsakanou          #+#    #+#              #
#    Updated: 2023/12/21 20:56:15 by nsakanou         ###   ########.fr        #
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
	builtin/pwd.c \
	builtin/cd.c \
	builtin/built_utils.c \
	builtin/echo.c \
	builtin/env.c \
	builtin/unset.c \
	builtin/env_utils.c

#	builtin/builtin.c \
	builtin/export.c \
s
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