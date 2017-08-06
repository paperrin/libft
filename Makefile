# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paperrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:00:36 by paperrin          #+#    #+#              #
#    Updated: 2017/08/06 17:44:02 by paperrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-g -Wall -Wextra -Werror

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
				ft_strndup.c		\
				ft_wstrdup.c		\
				ft_strcpy.c			\
				ft_wstrcpy.c		\
				ft_strncpy.c		\
				ft_strcat.c			\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strchr_any.c		\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strnstr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_atoi_base.c		\
				ft_atoi_hex.c		\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strupr.c			\
				ft_strlwr.c			\
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
				ft_strnjoin.c		\
				ft_wstrjoin.c		\
				ft_wstrjoin_free.c	\
				ft_strtrim.c		\
				ft_strsplit.c		\
				ft_itoa.c			\
				ft_itoa_base.c		\
				ft_itoa_hex.c		\
				ft_itoa_oct.c		\
				ft_itoa_bin.c		\
				ft_itoa_dec.c		\
				ft_putchar.c		\
				ft_putwchar.c		\
				ft_putnchar.c		\
				ft_putstr.c			\
				ft_putnstr.c		\
				ft_putwstr.c		\
				ft_putendl.c		\
				ft_putnbr.c			\
				ft_putchar_fd.c		\
				ft_putwchar_fd.c	\
				ft_putstr_fd.c		\
				ft_putnstr_fd.c		\
				ft_putwstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_tab_init.c		\
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
				ft_lstlen.c			\
				ft_get_next_line.c	\
				ft_sqrt.c			\
				ft_rbtree_new.c		\
				ft_rbtree_add.c		\
				ft_rbtree_print.c	\
				ft_hash_string.c	\
				ft_wchar.c			\
				math/ft_vec3f.c				\
				math/ft_vec3d.c				\
				math/ft_matrix.c			\
				math/ft_matrix_multiply.c	\
				math/ft_matrix_translate.c	\
				math/ft_matrix_rot.c		\
				math/ft_matrix_scale.c		\
				printf/ft_printf_core.c				\
				printf/ft_printf_parse.c			\
				printf/ft_printf_parse_field.c		\
				printf/ft_printf_parse_number.c		\
				printf/ft_printf_parse_int.c		\
				printf/ft_printf_parse_char.c		\
				printf/ft_printf_parse_pointer.c	\
				printf/ft_printf_parse_string.c		\
				printf/ft_printf_parse_none.c		\
				printf/ft_printf_format_result.c	\
				printf/ft_printf_get_bracket_str.c	\
				printf/ft_sprintf.c					\
				printf/ft_snprintf.c				\
				printf/ft_asprintf.c				\
				printf/ft_dprintf.c					\
				printf/ft_printf.c

SRC			=	$(CFILES:%=$(SRC_DIR)%)

OBJ			=	$(CFILES:%.c=$(OBJ_DIR)%.o)

# # # # #

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					ar rc $(NAME) $(OBJ)
					ranlib $(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)math
					@mkdir -p $(OBJ_DIR)printf
					gcc $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean			:
						$(RM) $(OBJ_DIR)

fclean			:	clean
						$(RM) $(NAME)

re				:	fclean all

norm			:
	@echo "\x1b[35m\n.==================[ \x1b[0m\c"
	@echo "\x1b[35;1mNormi-Check\x1b[0m\c"
	@echo " \x1b[35m]==================.\x1b[31;1m"
	@norminette include/ src/ \
		| tr "\n" "@" \
		| sed -e "s/Norme: /$$/g" \
		| tr "$$" "\n" \
		| grep -e Error -e Warning \
		| tr "@" "\n" \
		| sed "N;$$!P;$$!D;$$d"
	@echo "\x1b[0m\x1b[35m\c"
	@echo ".___________________________________________________.\n\x1b[0m"

.PHONY : all, test, clean, fclean, re, norm
