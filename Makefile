# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 14:09:43 by nsakanou          #+#    #+#              #
#    Updated: 2024/01/11 15:52:41 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# Libft+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

INCLUDES = -I ./includes -I $(LIBDIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
RM = rm -f

SRCS =srcs/builtin/built_utils.c \
	srcs/builtin/builtin.c \
	srcs/builtin/cd.c \
	srcs/builtin/echo.c \
	srcs/builtin/env.c \
	srcs/builtin/env_utils.c \
	srcs/builtin/exit.c \
	srcs/builtin/export.c \
	srcs/builtin/pwd.c \
	srcs/builtin/unset.c \

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
