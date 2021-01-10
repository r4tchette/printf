/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:27:44 by yeonkim           #+#    #+#             */
/*   Updated: 2021/01/10 12:37:11 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static size_t	int_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n /= -10;
		len += 2;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int		is_odd(int n)
{
	if (n % 2)
		return (1);
	return (0);
}

static int		round_up(char *buf, int idx)
{
	while (idx >= 0)
	{
		if (buf[idx] == '9')
			idx--;
		else
		{
			buf[idx]++;
			return (0);
		}
	}
	return (1);
}

char			*ft_ftoa(double decimal, int precision)
{
	char	*res;
	char	buf[128];
	int		integer;
	int		idx;

	precision = (precision == -1) ? 6 : precision;
	integer = (int)decimal;
	decimal -= (int)decimal;
	idx = 0;
	if (precision == 0)
		buf[idx++] = '0';
	else
		while(idx < precision)
		{
			decimal *= 10.0;
			buf[idx++] = (int)decimal + '0';
			decimal -= (int)decimal;
		}
	buf[idx--] = 0;
	if (decimal > 0.5 || (decimal == 0.5 && is_odd(buf[idx] - '0')))
		integer += round_up(buf, idx);
	res = ft_calloc(int_len(integer) + ft_strlen(buf) + 2, sizeof(char));
	ft_strlcpy(res, ft_itoa(integer), int_len(integer) + 1);
	ft_strlcat(res, ".", ft_strlen(res) + 2);
	ft_strlcat(res, buf, ft_strlen(res) + ft_strlen(buf) + 1);
	return (res);
}
