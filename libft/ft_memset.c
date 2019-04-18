/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:07:08 by anerus            #+#    #+#             */
/*   Updated: 2018/10/29 18:44:57 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *memptr, int val, size_t num)
{
	char	*str;
	size_t	i;

	i = 0;
	str = memptr;
	while (i < num)
	{
		str[i] = val;
		i++;
	}
	return (str);
}
