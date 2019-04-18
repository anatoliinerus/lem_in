/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:44:37 by anerus            #+#    #+#             */
/*   Updated: 2018/11/03 15:57:19 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = dest;
	while (++i < count)
	{
		*(ptr + i) = *((unsigned char *)source + i);
		if (*((unsigned char *)source + i) == (unsigned char)ch)
			return (dest + i + 1);
	}
	return (NULL);
}
