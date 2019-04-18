/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:50:40 by anerus            #+#    #+#             */
/*   Updated: 2018/11/07 17:37:36 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	p;
	int		solve;
	size_t	k;

	i = -1;
	if (!ft_strlen(little))
		return ((char *)big);
	while (*(big + ++i) && i < len)
	{
		p = 0;
		if (*(big + i) == *little)
		{
			k = i;
			solve = 1;
			while (*(big + k) && *(little + p) && k < len)
			{
				if (*(big + k++) != *(little + p++))
					solve = 0;
			}
			if (solve && !*(little + p))
				return ((char *)(big + i));
		}
	}
	return (NULL);
}
