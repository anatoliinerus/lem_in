/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:57:09 by anerus            #+#    #+#             */
/*   Updated: 2018/11/06 17:18:47 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	size_t			i;
	unsigned char	*src;

	if (destptr == NULL && srcptr == NULL)
		return (NULL);
	src = (unsigned char *)srcptr;
	i = 0;
	while (i < num)
	{
		ft_memset((void *)destptr + i, src[i], 1);
		i++;
	}
	return (destptr);
}
