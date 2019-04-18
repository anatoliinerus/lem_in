/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:31:40 by anerus            #+#    #+#             */
/*   Updated: 2018/11/04 18:14:17 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *a, const char *b)
{
	int		i;
	int		j;
	int		k;
	int		good;

	if (!ft_strlen(b))
		return ((char *)a);
	i = -1;
	good = 0;
	while (*(a + ++i) && !good)
	{
		if (*(a + i) == *(b + 0))
		{
			j = 0;
			k = i;
			good = 1;
			while (*(b + j))
				if (*(b + j++) != *(a + k++))
					good = 0;
			if (good)
				return ((char *)a + i);
		}
	}
	return (NULL);
}
