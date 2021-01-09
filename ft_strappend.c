/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:21 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/12 14:28:21 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strappend(char **s, char const c)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(*s);
	if (!(ptr = ft_calloc(len + 2, sizeof(char))))
		return (0);
	ft_strlcpy(ptr, *s, len + 1);
	ptr[len] = c;
	free(*s);
	*s = ptr;
	return (1);
}
