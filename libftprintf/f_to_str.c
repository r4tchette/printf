#include "libftprintf.h"

static int	sign_double(double *decimal)
{
	int	sign;

	sign = 1;
	if (*decimal < 0)
	{
		sign *= -1;
		*decimal *= -1;
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

int		f_to_str(t_format format, va_list *ap)
{
	double	decimal;
	char	*res;
	char	pad;
	int		dir;
	int		sign;

	//printf(" << format width : %d >> ", format.width);

	decimal = va_arg(*ap, double);
	sign = sign_double(&decimal);
	format.precision = (!format.flag['.']) ? 6 : format.precision;
	//format.precision = (format.precision < 0) ? 0 : format.precision;
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
			pad_char(&res, ' ', format.width - ft_strlen(res), -1);
		else
			pad_char(&res, pad, format.width - ft_strlen(res), dir);
	}
	if (sign == -1)
		relocate_sign(&res);
	return (print_buf(&res));
}