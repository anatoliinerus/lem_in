/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:47:19 by anerus            #+#    #+#             */
/*   Updated: 2018/11/09 18:51:04 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sort_dig(int *sort, int size)
{
	int i;
	int tmp;

	i = 0;
	if (size == 0)
		return (0);
	while (i < size - 1)
	{
		if (sort[i] > sort[i + 1])
		{
			tmp = sort[i + 1];
			sort[i + 1] = sort[i];
			sort[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (0);
}
