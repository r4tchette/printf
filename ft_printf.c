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
	format->width = 0;
	format->precision = 0;
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
	printf("tmp is %s\n", *dst);
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
	//printf("res : %s\n", *res);
	//write(1, &str, 16);
	//write(1, &": ", 2);
}

char	*to_string(char **res, t_format format, va_list *ap)
{
	char	*tmp;
	int		len;

	if (format.type == '%')
	{
		return (strdup("%"));
	}
	else if (format.type == 'c')
	{
		*res = ft_calloc(2, sizeof(char));
		(*res)[0] = va_arg(*ap, int);
	}
	else if (format.type == 's')
	{
		*res = strdup((char *)va_arg(*ap, int));
		printf("		res : %s\n", *res);
	}
	else if (format.type == 'p')
	{
		*res = format_p((long long)va_arg(*ap, long long));
	}
	else if (format.type == 'd' || format.type == 'i')
	{
		*res = ft_itoa(va_arg(*ap, int));
	}
	else if (format.type == 'u')
	{
		*res = ft_ltoa((long long)va_arg(*ap, unsigned int));
	}
	else if (format.type == 'x' || format.type == 'X')
	{
		*res = ft_xtoa((unsigned int)va_arg(*ap, unsigned int), format.type);
	}
	else
		printf("undefined format type!\n");
	if (format.flag['+'] && (*res)[0] != '-')
	{
		if (format.type == 'd' || format.type == 'i')
			*res = ft_strjoin("+", *res);
	}
	len = format.width - ft_strlen(*res);
	if (len > 0)
	{
		printf("length is %d\n", len);
		if (format.flag['0'] && !format.flag['-'])
			ft_setstr(&tmp, format.width - ft_strlen(*res), '0');
		else
			ft_setstr(&tmp, format.width - ft_strlen(*res), ' ');
		printf("tmp is %s\n", tmp);
		if (format.flag['-'])
			*res = ft_strjoin(*res, tmp);
		else
			*res = ft_strjoin(tmp, *res);
	}
	free(tmp);

	//format.flag['-']
	return (*res);
}

char	*parse_format(char **res, char *str, va_list *ap)
{
	t_format	format;
	int			i;

	init_format(&format);
	i = 0;
	while (str[i])
	{
		printf("'%c'", str[i]);
		if (is_type(str[i]))
		{
			format.type = str[i];
			return (to_string(res, format, ap));
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
			printf("format width : %d\n", format.width);
			i--;
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

int		ft_printf(char *str, ...)
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
			printf("\nparse_format(%c) : ", str[i]);
			if (parse_format(&tmp, &str[i + 1], &ap))
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
	//test("%12s\n", "abc");
	ft_printf("%04sABC%s%%%s, <%0-10s>\n", "abc", "xxxxx", "!@#", "123123");
	printf("res  : [%04sABC%s%%%s, <%0-10s>\n]", "abc", "xxxxx", "!@#", "123123");
	ft_printf("[%-010d]\n", 123);
	printf("[%-010d]\n", 123);
	ft_printf("%c%c%c\n", 'a', 'b', 'c');
	//test("%s,   %+*d, %c\n", "abcdefg", i, i, c);
	printf("format p : %017p\n", &i);
	ft_printf("%017p\n", &i);
	printf("format i : [%i]\n", 123);
	ft_printf("%0-+20u", 1);
	printf("format u : [%0-+20u]\n", 1);
	ft_printf("%x", 1023);
	printf("format x : [%x]\n", 1023);
	return (0);
}
