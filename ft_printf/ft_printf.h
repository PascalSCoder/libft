/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 12:23:37 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/02/17 16:14:06 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

typedef struct		s_argdata
{
	char	*str;
	char	*prefix;
	size_t	len;
}					t_argdata;

typedef struct		s_bytelist
{
	char				*buffer;
	size_t				len;
	struct s_bytelist	*next;
}					t_bytelist;

typedef struct		s_flags
{
	char	minus;
	char	zero;
	char	has_asterix;
	char	has_precision;
	int		field_width;
	int		precision;
	char	hashtag;
	char	whitespace;
	char	plus;
	char	l;
	char	h;
}					t_flags;

void				parse_fw(char **input, t_flags *flags, va_list args);
void				parse_precision(char **input, t_flags *flags, va_list args);
void				parse_typemodifier(char **input, t_flags *flags);
void				parse_flags(char **input, t_flags *flags);

int					ft_printf(const char *input, ...);
unsigned long long	get_unsigned_arg(va_list args, t_flags flags);
void				numflagrestr(t_flags *flags, t_argdata *data);
void				fw_to_precision(t_flags *flags, t_argdata *data);

char				arg_char(va_list args, t_flags flags, int *written);
char				arg_string(va_list args, t_flags flags, int *written);
char				arg_signednum(va_list args, t_flags flags, int *written);
char				arg_unsignednum(va_list args, t_flags flags, int *written);
char				arg_pointer(va_list args, t_flags flags, int *written);
char				arg_upperhex(va_list args, t_flags flags, int *written);
char				arg_lowerhex(va_list args, t_flags flags, int *written);
char				arg_percent(t_flags flags, int *written);
char				arg_nwritten(va_list args, int *written);
char				arg_double(va_list args, t_flags flags, int *written);

char				*compose_output(t_flags flags, t_argdata *data);
char				write_till_param(char **input, int *written);
char				write_out(char *str, size_t len, int *written);

void				bytelist_addfront(t_bytelist **list, t_bytelist *new);
void				bytelist_addback(t_bytelist **list, t_bytelist *new);
size_t				bytelist_getlen(t_bytelist *list);
size_t				bytelist_combine(t_bytelist *list, char **dest);
t_bytelist			*bytelist_new(char *str, size_t len);
char				*bytelist_free(t_bytelist *list);

#endif
