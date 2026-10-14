# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/22 18:25:18 by salegari          #+#    #+#              #
#    Updated: 2026/10/14 19:42:49 by salegari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARFLAGS = -rcs

RM = rm -f

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC =	ft_strlen.c\
	ft_isdigit.c\
	ft_isalpha.c\
	ft_isprint.c\
	ft_isascii.c\
	ft_isalnum.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strncmp.c\
	ft_strchr.c\
	ft_strchr.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_memmove.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_striteri.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_intpchar.c \
	ft_intpstr.c \
	ft_intputnbr.c \
	ft_printf.c \
	ft_putnbr_base.c \
	ft_putnbr_unsg.c \
	ft_putptr.c \
	ft_str_is_numeric.c \

OBJ = $(SRC:.c=.o)

INCLUDE = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@ $(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	@ $(CC) $(CCFLAGS) -c -o $@ $<
clean:
	$(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
