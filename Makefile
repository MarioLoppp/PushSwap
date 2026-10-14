# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/07 19:50:13 by salegari          #+#    #+#              #
#    Updated: 2026/10/14 18:13:52 by marlope3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

SRC_DIR = src
BONUS_SRC_DIR = bonus

SRCS = $(SRC_DIR)/main.c\
BONUS_SRCS = $(BONUS_SRC_DIR)/checker_bonus.c\
	   
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT) -lft

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS)

$(LIBFT_LIB):
	make -C $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

asan: CFLAGS += -fsanitize=address
asan: CFLAGS += -g3
asan: re

.PHONY: all clean fclean re asan bonus
