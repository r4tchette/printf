#include "libftprintf.h"

static int	sign_int(char **str)
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

static int	relocate_sign(char **str)
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

int			d_to_str(t_format format, va_list *ap)
{
	char	*res;
	char	pad;
	int		dir;
	int		sign;
	int		num;

	num = va_arg(*ap, int);
	res = (num == 0 && format.flag['.'] && format.precision == 0) ? ft_calloc(1, sizeof(char)) : ft_itoa(num);
	sign = sign_int(&res);
	pad = (format.flag['.'] && format.precision > 0) ? '0' : ' ';
	if (format.precision > (int)ft_strlen(res))
		pad_char(&res, pad, format.precision - ft_strlen(res), 1);
	if (sign == -1)
		pad_char(&res, '-', 1, 1);
	if (format.width > (int)ft_strlen(res))
	{
		pad = (format.flag['0'] && !format.flag['-'] && pad == ' ' && !(format.flag['.'] && format.precision == 0)) ? '0' : ' ';
		dir = (format.flag['-']) ? -1 : 1;
		pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	if (sign == -1)
		relocate_sign(&res);
	return (print_buf(&res));
}