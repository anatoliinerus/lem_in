/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 00:30:36 by anerus            #+#    #+#             */
/*   Updated: 2018/11/08 15:53:13 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *memptr, int val, size_t i)
{
	int				j;
	unsigned char	*str;
	unsigned char	pizda;

	j = 0;
	pizda = (unsigned char)val;
	str = (unsigned char *)memptr;
	while (i--)
	{
		if (str[j] == pizda)
			return (str + j);
		j++;
	}
	return (0);
}
