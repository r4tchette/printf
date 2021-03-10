#include "libftprintf.h"

int	n_to_str(va_list *ap, int len)
{
	int	*ptr;

	ptr = va_arg(*ap, int *);
	if (ptr)
		*ptr = len;
	return (0);
}
