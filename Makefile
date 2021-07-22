# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pascal <pascal@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/02 15:18:24 by pascal        #+#    #+#                  #
#    Updated: 2021/07/22 14:03:21 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
LIBFT_C		=	ft_abs.c\
				ft_atof.c\
				ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_charcmpset.c\
				ft_decitohex.c\
				ft_dtoa.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_iswhitespace.c\
				ft_itoa.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdup.c\
				ft_memmove.c\
				ft_memset.c\
				ft_power.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_realloc.c\
				ft_realloc_double.c\
				ft_split.c\
				ft_split_free.c\
				ft_split_set.c\
				ft_strchr.c\
				ft_strcmp.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnjoin.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtolower.c\
				ft_strtoupper.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_ulltoa.c\
				ft_numlen.c\
				ft_unumlen.c

GNL_C		=	get_next_line.c\
				get_next_line_utils.c

PRINTF_C	=	arg_di.c\
				arg_f.c\
				arg_n.c\
				arg_p.c\
				arg_percent.c\
				arg_s.c\
				arg_x.c\
				bytelist.c\
				bytelist_free.c\
				compose.c\
				flags_parse.c\
				flagtools.c\
				ft_printf.c\
				write_out.c

VECTOR_C	=	vector_add.c\
				vector_clear.c\
				vector_free.c\
				vector_getvalue.c\
				vector_indexof.c\
				vector_new.c\
				vector_newptr.c\
				vector_realloc.c\
				vector_removeat.c\
				vector_toarray.c

LIBFT_O		=	$(LIBFT_C:%.c=%.o)
GNL_O		=	$(GNL_C:%.c=get_next_line/%.o)
PRINTF_O	=	$(PRINTF_C:%.c=ft_printf/%.o)
VECTOR_O	=	$(VECTOR_C:%.c=vector/%.o)

CFLAGS		=	-Wall -Werror -Wextra
CC			=	gcc

all: $(NAME)

$(NAME): $(LIBFT_O) $(GNL_O) $(PRINTF_O) $(VECTOR_O)
	ar -crs $(NAME) $(LIBFT_O) $(GNL_O) $(PRINTF_O) $(VECTOR_O)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(LIBFT_O)
	rm -f $(GNL_O)
	rm -f $(PRINTF_O)
	rm -f $(VECTOR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
