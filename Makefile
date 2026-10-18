# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/07 19:50:13 by salegari          #+#    #+#              #
#    Updated: 2026/10/15 19:34:17 by salegari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

SRC_DIR = src
BONUS_SRC_DIR = bonus

SRCS = $(SRC_DIR)/main.c\
		$(SRC_DIR)/bench.c\
		$(SRC_DIR)/bubble.c\
		$(SRC_DIR)/checks.c\
		$(SRC_DIR)/chunks.c\
		$(SRC_DIR)/disorder_index.c\
		$(SRC_DIR)/frees.c\
		$(SRC_DIR)/lists.c\
		$(SRC_DIR)/moves.c\
		$(SRC_DIR)/parser.c\
		$(SRC_DIR)/radix.c\
		$(SRC_DIR)/reverse_rotate.c\
		$(SRC_DIR)/rotate.c\

BONUS_SRCS = $(BONUS_SRC_DIR)/checker_bonus.c\
		$(BONUS_SRC_DIR)/execute_bonus.c\
		$(BONUS_SRC_DIR)/read_bonus.c\
		$(BONUS_SRC_DIR)/utils_bonus.c\
		$(SRC_DIR)/checks.c\
		$(SRC_DIR)/frees.c\
		$(SRC_DIR)/lists.c\
		$(SRC_DIR)/parser.c
	   
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT) -lft

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS) -L$(LIBFT) -lft

$(OBJS) $(BONUS_OBJS): includes/push_swap.h libft/libft.h
$(BONUS_SRC_DIR)/checker_bonus.o $(BONUS_SRC_DIR)/execute_bonus.o \
$(BONUS_SRC_DIR)/read_bonus.o $(BONUS_SRC_DIR)/utils_bonus.o: includes/checker_bonus.h

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
