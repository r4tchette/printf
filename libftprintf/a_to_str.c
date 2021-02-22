#include "libftprintf.h"

int	a_to_str(t_format format)
{
	char	*res;
	char	pad;
	int		dir;

	if (!(res = ft_strdup("%")))
		return (0);
	if (format.width < 0)
	{
		format.flag['-'] = 1;
		format.width *= -1;
	}
	if (format.width > 1)
	{
		pad = (format.flag['0'] && !format.flag['-']) ? '0' : ' ';
		dir = format.flag['-'] ? -1 : 1;
		pad_char(&res, pad, format.width - 1, dir);
	}
	return (print_buf(&res));
}