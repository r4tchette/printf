/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:44:30 by yeonkim           #+#    #+#             */
/*   Updated: 2020/11/19 13:44:30 by yeonkim          ###   ########.fr       */
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
		c == '0' ||	c == '#' || c == '.')
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
	format->width = -1;
	format->precision = -1;
	format->type = 0;
}

int		ft_setstr(char *dst, int len, char ch)
{
	int	i;

	if (!(dst = ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = ch;
		i++;
	}
	return (1);
}

char	*to_string(t_format format, char *str, va_list *ap)
{
	char	*res;
	char	*tmp;
	int		len;

	if (format.type == '%')
		return (strdup("%"));
	res = strdup((char *)va_arg(*ap, int));
	/*
	len = format.width - ft_strlen(res);
	if (len > 0)
	{
		if (format.flag['0'])
			ft_setstr(tmp, format.width - ft_strlen(res), '0');
		else
			ft_setstr(tmp, format.width - ft_strlen(res), ' ');
		if (format.flag['-'])
			ft_strjoin(res, tmp);
		else
			ft_strjoin(tmp, res);
	}
	free(tmp);
	*/
	//format.flag['-']
	return (res);
}

char	*parse_format2(char *str, va_list *ap)
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
			return (to_string(format, str, ap));
		}
		else if (is_flag(str[i]))
			format.flag[str[i]] = 1;
		else if (str[i] == '*')
		{
			format.width = (int)va_arg(*ap, int);
		}
		else if (is_num(str[i]) && str[i] != '0')
		{
			while(is_num(str[i]))
			{
				format.width *= 10;
				format.width += str[i] - '0';
				i++;
			}
		}
		else if (str[i] == '.')
		{
			i++;
			if (str[i] == '*')
			{
				format.precision = va_arg(*ap, int);
			}
			else
			{
				while(is_num(str[i]))
				{
					format.width *= 10;
					format.width += str[i] - '0';
					i++;
				}
			}

		}
		i++;
	}
	return (NULL);
}

char	*parse_format(char *str)
{
	char	buf[1024];
	int		i;

	i = 0;
	while (!is_type(str[i]))
	{
		buf[i] = str[i];
		i++;
	}
	if (is_type(str[i]))
		buf[i] = str[i];
	buf[i + 1] = 0;
	return (strdup(buf));
}

int		test(char *str, ...)
{
	va_list	ap;
	int		i;
	int		size;
	char	*buf;
	char	*tmp;

	size = 1024;
	buf = ft_calloc(size, sizeof(char));
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (tmp = parse_format2(str + i + 1, &ap))
				printf("[%s(%d)]", tmp, ft_strlen(tmp));
			else
				return (0);
			ft_strlcat(buf, tmp, ft_strlen(buf) + ft_strlen(tmp) + 1);
			free(tmp);
			while (!is_type(str[++i]));
		}
		else
		{
			printf("%c", str[i]);
			ft_strlcat(buf, str + i, ft_strlen(buf) + 2);
		}
		i++;
	}
	printf("\n<< result >>\n");
	printf("buf  : [%s]\n", buf);
	printf("size : [%d]\n", ft_strlen(buf));
	va_end(ap);
	return (0);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, str);
	printf("%s\n", str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				printf("%c", va_arg(ap, int));
			else if (str[i + 1] == 's')
				printf("%s", va_arg(ap, int));
			else if (str[i + 1] == 'p')
				printf("%p", va_arg(ap, int));
			else if (str[i + 1] == 'd')
				printf("%d", va_arg(ap, int));
			else if (str[i + 1] == 'i')
				printf("%i", va_arg(ap, int));
			else if (str[i + 1] == 'u')
				printf("%u", va_arg(ap, int));
			else if (str[i + 1] == 'x')
				printf("%x", va_arg(ap, int));
			else if (str[i + 1] == 'X')
				printf("%X", va_arg(ap, int));
			else if (str[i + 1] == '%')
				printf("%");
			i++;
		}
		else
		{
			printf("%c", str[i]);
		}
		i++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	int		i;
	char	c;
	double	a;

	i = 1;
	c = 'c';
	a = 3.141592653;
	//ft_printf("%d, %c\n", i, c);
	//printf("%0*.*lf\n", 15, 7, a);
	printf("%+s\n", "12345");
	test("%sABC%s%%%s\n", 1, "abc", "123", "!@#");
	//test("%s,   %+*d, %c\n", "abcdefg", i, i, c);
	return (0);
}
