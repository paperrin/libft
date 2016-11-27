# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paperrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:00:36 by paperrin          #+#    #+#              #
#    Updated: 2016/11/26 19:45:48 by paperrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

SRC_DIR		=	./src/

OBJ_DIR		=	./obj/

INC_DIR		=	./include/

CFILES		=	ft_swap.c			\
				ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memrevcpy.c		\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_wstrlen.c		\
				ft_strdup.c			\
				ft_wstrdup.c		\
				ft_strcpy.c			\
				ft_wstrcpy.c		\
				ft_strncpy.c		\
				ft_strcat.c			\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strnstr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_memalloc.c		\
				ft_memdel.c			\
				ft_strnew.c			\
				ft_strdel.c			\
				ft_strclr.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strequ.c			\
				ft_strnequ.c		\
				ft_strsub.c			\
				ft_strjoin.c		\
				ft_wstrjoin.c		\
				ft_strjoin_free.c	\
				ft_wstrjoin_free.c	\
				ft_strtrim.c		\
				ft_strsplit.c		\
				ft_itoa.c			\
				ft_putchar.c		\
				ft_putwchar.c		\
				ft_putnchar.c		\
				ft_putstr.c			\
				ft_putwstr.c		\
				ft_putendl.c		\
				ft_putnbr.c			\
				ft_putchar_fd.c		\
				ft_putwchar_fd.c	\
				ft_putstr_fd.c		\
				ft_putwstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_lstnew.c			\
				ft_lstdelone.c		\
				ft_lstdel.c			\
				ft_lstadd.c			\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_lstfind.c		\
				ft_lstdelfind.c		\
				ft_lstat.c			\
				ft_lstpush.c		\
				ft_get_next_line.c	\
				ft_sqrt.c			\
				ft_rbtree_new.c		\
				ft_rbtree_add.c		\
				ft_rbtree_print.c	\
				ft_hash_string.c

SRC			=	$(CFILES:%=$(SRC_DIR)%)

OBJ			=	$(CFILES:%.c=$(OBJ_DIR)%.o)

# # # # #

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					ar rc $(NAME) $(OBJ)
					ranlib $(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
						mkdir -p $(OBJ_DIR)
						gcc $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean			:
						$(RM) $(OBJ_DIR)

fclean			:	clean
						$(RM) $(NAME)

re				:	fclean all
