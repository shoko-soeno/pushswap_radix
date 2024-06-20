# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 21:20:45 by ssoeno            #+#    #+#              #
#    Updated: 2024/06/20 08:40:30 by ssoeno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -O3 -MMD -MP -Iincludes

LIBFT = ./libft
SRCS =  $(wildcard src/*.c utils/*.c)
# CHECK_SRCS = $(wildcard utils/*.c) src/operations.c checker.c

OBJS = $(SRCS:.c=.o)
# CHECK_OBJS = $(CHECK_SRCS:.c=.o)
# DEPS=$(SRCS:.c=.d)

# all: $(NAME) $(CHECK)
all: $(NAME)

-include $(OBJS:.o=.d)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

# $(CHECK): $(CHECK_OBJS)
# 	@$(MAKE) -C $(LIBFT)
# 	@$(CC) $(CFLAGS) $(CHECK_OBJS) -L$(LIBFT) -lft -o $(CHECK)

clean:
	make -C ./libft fclean
	@$(RM) $(OBJS)
	# @$(RM) $(CHECK_OBJS)
	@$(RM) $(OBJS) $(OBJS:.o=.d)

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) $(NAME)
	# $(RM) $(CHECK)

re: fclean all

.PHONY: all clean fclean re