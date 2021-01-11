/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:44:30 by yeonkim           #+#    #+#             */
/*   Updated: 2021/01/11 17:57:57 by yeonkim          ###   ########.fr       */
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
		c == 'x' || c == 'X' || c == '%' ||\
		c == 'n' || c == 'f')
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
	format->precision = 0;
	format->type = 0;
}

int		print_buf(char **buf)
{
	int	len;

	len = ft_strlen(*buf);
	write(1, *buf, len);
	free(*buf);
	return (len);
}

int		print_buf_with_zero(char **buf, t_format format)
{
	int	len;

	len = ft_strlen(*buf);
	if (format.flag['-'])
	{
		write(1, "\0", 1);
		write(1, *buf, len);
	}
	else
	{
		write(1, *buf, len);
		write(1, "\0", 1);
	}
	free(*buf);
	return (len + 1);
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

int		c_to_str(t_format format, va_list *ap)
{
	char	*res;
	char	pad;
	int		dir;
	int		is_zero;

	if (!(res = ft_calloc(2, sizeof(char))))
		return (0);
	res[0] = (char)va_arg(*ap, int);
	is_zero = (res[0] == 0) ? 1 : 0;
	if (format.width < 0)
	{
		format.flag['-'] = 1;
		format.width *= -1;
	}
	if (format.width > 1)
	{
		pad = format.flag['0'] ? '0' : ' ';
		dir = format.flag['-'] ? -1 : 1;
		pad_char(&res, pad, format.width - 1, dir);
	}
	if (is_zero)
		return (print_buf_with_zero(&res, format));
	return (print_buf(&res));
}

int		s_to_str(t_format format, va_list *ap)
{
	char	*ptr;
	char	*res;
	int		dir;
	char	pad;

	if (!(ptr = va_arg(*ap, char *)))
		res = ft_strdup("(null)");
	else
		res = ft_strdup(ptr);
	if (format.flag['.'] && format.precision < (int)ft_strlen(res))
		res[format.precision] = 0;
	if (format.width > (int)ft_strlen(res))
	{
		dir = (format.flag['-'] ? -1 : 1);
		pad = (format.flag['0'] && !format.flag['-'] ? '0' : ' ');
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	return (print_buf(&res));
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

int		relocate_sign(char **str)
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

int		d_to_str(t_format format, va_list *ap)
{
	char	*res;
	char	pad;
	int		dir;
	int		sign;
	int		num;

	num = va_arg(*ap, int);
	res = (num == 0 && format.flag['.']) ? ft_calloc(1, sizeof(char)) : ft_itoa(num);
	sign = sign_int(&res);
	if (format.precision > (int)ft_strlen(res))
		pad_char(&res, '0', format.precision - ft_strlen(res), 1);
	if (sign == -1)
		pad_char(&res, '-', 1, 1);
	if (format.width > (int)ft_strlen(res))
	{
		pad = (format.flag['0'] && !format.flag['-'] && !format.flag['.'] ? '0' : ' ');
		dir = (format.flag['-'] ? -1 : 1);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	if (format.flag[' '] == 1 && is_num(res[0]))
		pad_char(&res, ' ', 1, 1);
	if (sign == -1)
		relocate_sign(&res);
	return (print_buf(&res));
}

char	convert_to_hex(unsigned int n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'A');
}

int		a_to_str(t_format format)
{
	char	*res;
	char	pad;
	int		dir;

	res = ft_strdup("%");
	pad = (format.flag['0'] && !format.flag['-'] ? '0' : ' ');
	dir = (format.flag['-'] ? -1 : 1);
	pad_char(&res, pad, format.width - ft_strlen(res), dir);
	return (print_buf(&res));
}

int		p_to_str(t_format format, va_list *ap)
{
	long long	ptr;
	char		*res;
	char		pad;
	int			dir;
	int			i;

	ptr = va_arg(*ap, long long);
	res = ft_calloc(9, sizeof(char));
	i = 8;
	while (i > 0)
	{
		res[--i] = convert_to_hex(ptr % 16);
		ptr /= 16;
	}
	if (format.width > (int)ft_strlen(res))
	{
		pad = (format.flag['0'] && !format.flag['-'] && !format.flag['.'] ? '0' : ' ');
		dir = (format.flag['-'] ? -1 : 1);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	return (print_buf(&res));
}

int		u_to_str(t_format format, va_list *ap)
{
	char	*res;
	char	pad;
	int		dir;

	res = ft_utoa(va_arg(*ap, unsigned int));
	if (format.precision > (int)ft_strlen(res))
		pad_char(&res, '0', format.precision - ft_strlen(res), 1);
	if (format.width > (int)ft_strlen(res))
	{
		pad = (format.flag['0'] ? '0' : ' ');
		dir = (format.flag['-'] ? -1 : 1);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	return (print_buf(&res));
}

int		x_to_str(t_format format, va_list *ap)
{
	unsigned int	num;
	char			*res;
	char			pad;
	int				dir;

	num = va_arg(*ap, unsigned int);
	res = ft_xtoa(num, format.type);
	if (format.precision > (int)ft_strlen(res))
		pad_char(&res, '0', format.precision - ft_strlen(res), 1);
	if (format.width > (int)ft_strlen(res))
	{
		pad = ((format.flag['0'] && !format.flag['-']) ? '0' : ' ');
		dir = (format.flag['-'] ? -1 : 1);
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	return (print_buf(&res));
}

int		f_to_str(t_format format, va_list *ap)
{
	double	decimal;
	char	*res;
	char	pad;
	int		dir;
	int		sign;

	decimal = va_arg(*ap, double);
	sign = 1;
	if (decimal < 0)
	{
		sign = -1;
		decimal *= -1;
	}
	res = ft_ftoa(decimal, format.precision);
	if (format.precision > (int)ft_strlen(res))
		pad_char(&res, '0', format.precision - ft_strlen(res), 1);
	if (sign == -1)
		pad_char(&res, '-', 1, 1);
	if (format.width > (int)ft_strlen(res))
	{
		pad = format.flag['0'] ? '0' : ' ';
		dir = format.flag['-'] ? -1 : 1;
		if (pad == '0' && dir == -1)
			pad_char(&res, ' ', 1, -1);
		else
			pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	if (format.flag[' '] == 1 && is_num(res[0]))
		pad_char(&res, ' ', 1, 1);
	if (sign == -1)
		relocate_sign(&res);
	return (print_buf(&res));
}

int		n_to_str(va_list *ap, int len)
{
	int	*ptr;

	ptr = va_arg(*ap, int *);
	if (ptr)
		*ptr = len;
	return (len);
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

int		to_str(t_format format, va_list *ap, int len)
{
	if (format.type == '%')
		return (a_to_str(format));
	else if (format.type == 'c')
		return (c_to_str(format, ap));
	else if (format.type == 's')
		return (s_to_str(format, ap));
	else if (format.type == 'p')
		return (p_to_str(format, ap));
	else if (format.type == 'd' || format.type == 'i')
		return (d_to_str(format, ap));
	else if (format.type == 'u')
		return (u_to_str(format, ap));
	else if (format.type == 'x' || format.type == 'X')
		return (x_to_str(format, ap));
	else if (format.type == 'f')
		return (f_to_str(format, ap));
	else if (format.type == 'n')
		return (n_to_str(ap, len));
	return (-1);
}

int		print_format(char *str, va_list *ap, int len)
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
			return (to_str(format, ap, len));
		}
		else if (is_flag(str[i]))
			format.flag[(int)str[i++]] = 1;
		else if (is_num(str[i]) || str[i] == '*')
		{
			if (format.flag['.'] == 0)
			{
				if (str[i] == '0')
					format.flag[(int)str[i++]] = 1;
				get_width(&format, &i, str, ap);
			}
			else
				get_precision(&format, &i, str, ap);
		}
	}
	return (0);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;
	int		ret;

	len = 0;
	i = -1;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ret = print_format(&str[i + 1], &ap, len);
			if (ret < 0)
				return (-1);
			len += ret;
			while (!is_type(str[++i]));
		}
		else
		{
			write(1, str + i, 1);
			len++;
		}
	}
	return (len);
}
