/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:44:30 by yeonkim           #+#    #+#             */
/*   Updated: 2020/12/29 10:25:48 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"

#include <string.h>

typedef struct	s_format
{
	char	flag[128];
	int		width;
	int		precision;
	char	length;
	char	type;
}				t_format;

int		is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' ||\
		c == '#' || c == '.')
		return (1);
	return (0);
}

int		is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' ||\
		c == 'd' || c == 'i' || c == 'u' ||\
		c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	init_format(t_format *format)
{
	format->flag['-'] = 0;
	format->flag['+'] = 0;
	format->flag[' '] = 0;
	format->flag['0'] = 0;
	format->flag['#'] = 0;
	format->flag['.'] = 0;
	format->width = 0;
	format->precision = -1;
	format->type = 0;
}

int		ft_setstr(char **dst, int len, char ch)
{
	int	i;

	if (!(*dst = ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
	{
		(*dst)[i] = ch;
		i++;
	}
	//printf("tmp is %s\n", *dst);
	return (1);
}

char	convert_to_hex(unsigned int n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'A');
}

char	*format_p(long addr)
{
	char	*res;
	int		i;

	res = ft_calloc(9, sizeof(char));
	i = 8;
	while (i > 0)
	{
		res[--i] = convert_to_hex(addr % 16);
		addr /= 16;
	}
	return (res);
}

char	*format_s(va_list *ap)
{
	char	*src;
	char	*dst;

	src = (char *)va_arg(*ap, char *);
	if (!src)
		dst = ft_strdup("(null)");
	else
		dst = ft_strdup(src);
	return (dst);
}

int		format_type(char **res, char type, va_list *ap)
{
	if (type == '%')
		*res = ft_strdup("%");
	else if (type == 'c')
	{
		if (!(*res = ft_calloc(2, sizeof(char))))
			return (0);
		(*res)[0] = (char)va_arg(*ap, int);
	}
	else if (type == 's')
		*res = format_s(ap);
		//*res = ft_strdup((char *)va_arg(*ap, char *));
	else if (type == 'p')
		*res = format_p((long long)va_arg(*ap, long long));
	else if (type == 'd' || type == 'i')
		*res = ft_itoa(va_arg(*ap, int));
	else if (type == 'u')
		*res = ft_ltoa((long long)va_arg(*ap, unsigned int));
	else if (type == 'x' || type == 'X')
		*res = ft_xtoa((unsigned int)va_arg(*ap, unsigned int), type);
	else
		printf("undefined format type!\n");
	if (!(*res))
		return (0);
	return (1);
}

char	*to_string(char **res, t_format format, va_list *ap)
{
	char	*tmp;
	int		len;

	format_type(res, format.type, ap);
	if (format.flag['+'] && (*res)[0] != '-')
		if (format.type == 'd' || format.type == 'i')
			*res = ft_strjoin("+", *res);
	len = format.width - ft_strlen(*res);
	if (len > 0)
	{
		if (format.flag['0'] && !format.flag['-'])
			ft_setstr(&tmp, format.width - ft_strlen(*res), '0');
		else
			ft_setstr(&tmp, format.width - ft_strlen(*res), ' ');
		if (format.flag['-'])
			*res = ft_strjoin(*res, tmp);
		else
			*res = ft_strjoin(tmp, *res);
		free(tmp);
	}
	return (*res);
}

int		pad_char(char **res, char c, int len, int dir)
{
	char	*tmp;
	char	*pad;
	int		i;

	if (!(*res))
		return (0);
	if (!(pad = ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
		pad[i++] = c;
	if (dir == -1)
		tmp = ft_strjoin(*res, pad);
	else if (dir == 1)
		tmp = ft_strjoin(pad, *res);
	else
	{
		free(pad);
		return (-1);
	}
	free(*res);
	*res = tmp;
	return (1);
}

char	*c_to_str(t_format format, va_list *ap)
{
	char	*res;

	if (!(res = ft_calloc(2, sizeof(char))))
		return (0);
	res[0] = (char)va_arg(*ap, int);
	//printf("format width : %d\n", format.width);
	//printf("format precision : %d\n", format.precision);
	//printf("res : <%s>\n", res);
	if (format.width < 0)
	{
		format.flag['-'] = 1;
		format.width *= -1;
	}
	if (format.width > 1)
	{
		if (!format.flag['-'])
			pad_char(&res, ' ', format.width - 1, 1);
		else
			pad_char(&res, ' ', format.width - 1, -1);
	}
	return (res);
}

char	*s_to_str(t_format format, va_list *ap)
{
	char	*ptr;
	char	*str;
	char	*res;

	//printf("precision : %d\n", format.precision);
	if (!(ptr = va_arg(*ap, char *)))
		str = ft_strdup("(null)");
	else
		str = ft_strdup(ptr);
	if (format.precision != -1 && format.precision < ft_strlen(str))
	{
		res = ft_calloc(format.precision + 1, sizeof(char));
		ft_strlcpy(res, str, format.precision + 1);
		free(str);
		return (res);
	}
	res = str;
	return (res);
}

int		sign_int(char **str)
{
	char	*tmp;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if ((*str)[i] == '-')
		sign *= -1;
	if (sign == -1)
	{
		tmp = ft_calloc(ft_strlen((*str)), sizeof(char));
		while ((*str)[i + 1])
		{
			tmp[i] = (*str)[i + 1];
			i++;
		}
		(*str) = tmp;
	}
	return (sign);
}

int		set_sign_position(char **str)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '-')
			return (1);
		else if ((*str)[i] == '0')
		{
			(*str)[i++] = '-';
			while ((*str)[i])
			{
				if ((*str)[i] == '-')
				{
					(*str)[i] = '0';
					return (2);
				}
				i++;
			}
		}
		i++;                                                                                                                                                                                      
	}
	return (0);
}

char	*d_to_str(t_format format, va_list *ap)
{
	char	*res;
	char	pad;
	int		dir;
	int		sign;

	res = ft_itoa(va_arg(*ap, int));
	sign = sign_int(&res);
	if (format.precision > ft_strlen(res))
		pad_char(&res, '0', format.precision - ft_strlen(res), 1);
	if (sign == -1)
		pad_char(&res, '-', 1, 1);
	if (format.width > ft_strlen(res))
	{
		pad = (format.flag['0'] ? '0' : ' ');
		dir = (format.flag['-'] ? -1 : 1);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	if (format.flag[' '] == 1 && is_num(res[0]))
		pad_char(&res, ' ', 1, 1);
	if (sign == -1)
		set_sign_position(&res);
	return (res);
}

char	*p_to_str(t_format format, va_list *ap) 
{
	long long	ptr;
	char		*res;
	int			i;

	ptr = va_arg(*ap, long long);
	res = ft_calloc(9, sizeof(char));
	i = 8;
	while (i > 0)
	{
		res[--i] = convert_to_hex(ptr % 16);
		ptr /= 16;
	}
	if (format.width > ft_strlen(res))
	{
		if (format.flag['-'] == 1)
			pad_char(&res, ' ', format.width - ft_strlen(res), -1);
		else
			pad_char(&res, ' ', format.width - ft_strlen(res), 1);
	}
	return (res);
}

char	*u_to_str(t_format format, va_list *ap)
{
	char	*res;
	char	pad;
	int		dir;

	res = ft_utoa(va_arg(*ap, unsigned int));
	if (format.precision > ft_strlen(res))
		pad_char(&res, '0', format.precision - ft_strlen(res), 1);
	if (format.width > ft_strlen(res))
	{
		pad = (format.flag['0'] ? '0' : ' ');
		dir = (format.flag['-'] ? -1 : 1);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	return (res);
}

char	*x_to_str(t_format format, va_list *ap)
{
	unsigned int	num;
	char			*res;
	char			pad;
	int				dir;

	num = va_arg(*ap, unsigned int);
	res = ft_xtoa(num, format.type);
	if (format.precision > ft_strlen(res))
		pad_char(&res, '0', format.precision - ft_strlen(res), 1);
	if (format.width > ft_strlen(res))
	{
		pad = ((format.flag['0'] && !format.flag['-']) ? '0' : ' ');
		dir = (format.flag['-'] ? -1 : 1);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	return (res);
}

char	*to_str(t_format format, va_list *ap)
{
	char	*res;

	//printf("width : %d\n, precision : %d\n", format.width, format.precision);
	res = NULL;
	if (format.type == '%')
		res = ft_strdup("%");
	else if (format.type == 'c')
		res = c_to_str(format, ap);
	else if (format.type == 's')
		res = s_to_str(format, ap);
	else if (format.type == 'p')
		res = p_to_str(format, ap);
	else if (format.type == 'd' || format.type == 'i')
		res = d_to_str(format, ap);
	else if (format.type == 'u')
		res = u_to_str(format, ap);
	else if (format.type == 'x' || format.type == 'X')
		res = x_to_str(format, ap);
	else
		printf("undefined format type!\n");
	if (!res)
		return (0);
	return (res);
}

int		get_width(t_format *format, int *idx, char *str, va_list *ap)
{
	int	width;
	int	i;

	width = 0;
	i = (*idx);
	if (str[i] == '*')
	{
		width = (int)va_arg(*ap, int);
		if (width < 0)
		{
			width *= -1;
			format->flag['-'] = 1;
		}
		i++;
	}
	else if (is_num(str[i]))
		while(is_num(str[i]))
			width = 10 * width + (str[i++] - '0');
	else
		return (0);
	format->width = width;
	*idx = i;
	//printf("index after get_width : %c(%d)\n", str[i], i);
	return (1);
}

int		get_precision(t_format *format, int *idx, char *str, va_list *ap)
{
	int	precision;
	int	i;

	precision = 0;
	i = *idx;
	if (str[i] == '*')
	{
		precision = (int)va_arg(*ap, int);
		i++;
	}
	else if (is_num(str[i]))
		while(is_num(str[i]) && str[i])
		{
			precision *= 10;
			precision += str[i] - '0';
			i++;
		}
	else
		return (0);
	format->precision = precision;
	*idx = i;
	return (1);
}


char	*parse_format(char *str, va_list *ap)
{
	t_format	format;
	int			i;

	init_format(&format);
	i = 0;
	while (str[i])
	{
		if (is_type(str[i]))
		{
			format.type = str[i];
			return (to_str(format, ap));
		}
		else if (is_flag(str[i]))
			format.flag[str[i++]] = 1;
		else if (is_num(str[i]) || str[i] == '*')
		{
			if (format.flag['.'] == 0)
			{
				if (str[i] == '0')
					format.flag[str[i++]] = 1;
				get_width(&format, &i, str, ap);
			}
			else
				get_precision(&format, &i, str, ap);
		}
	}
	printf("no type charcater\n");
	return (0);
}

int		expand_string(char **buf, size_t *buf_size, size_t new_size)
{
	char	*tmp;

	if (*buf_size < new_size)
	{
		tmp = ft_strdup(*buf);
		free(*buf);
		*buf_size *= 2;
		if (!(*buf = ft_calloc(*buf_size, sizeof(char))))
			return (0);
		ft_strlcpy(*buf, tmp, ft_strlen(tmp) + 1);
		free(tmp);
	}
	return (1);
}

int		init_buf(char **buf, size_t *buf_size, int *i)
{
	*buf_size = 1024;
	if (!(*buf = ft_calloc(*buf_size, sizeof(char))))
		return (0);
	*i = -1;
	return (1);
}

int		print_buf(char **buf, va_list *ap)
{
	int	buf_len;

	buf_len = ft_strlen(*buf);
	printf("%s", *buf);
	free(*buf);
	va_end(*ap);
	return (buf_len);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	size_t	buf_size;
	char	*buf;
	char	*tmp;
	int		i;

	if (!(init_buf(&buf, &buf_size, &i)))
		return (-1);
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (!(tmp = parse_format(&str[i + 1], &ap)))
				return (-1);
			if (buf_size < ft_strlen(buf) + ft_strlen(tmp) + 1)
				expand_string(&buf, &buf_size, ft_strlen(buf) + ft_strlen(tmp) + 1);
			ft_strlcat(buf, tmp, ft_strlen(buf) + ft_strlen(tmp) + 1);
			free(tmp);
			while (!is_type(str[++i]));
		}
		else
			ft_strlcat(buf, str + i, ft_strlen(buf) + 2);
	}
	return (print_buf(&buf, &ap));
}
