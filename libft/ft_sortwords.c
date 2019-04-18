/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortwords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:39:21 by anerus            #+#    #+#             */
/*   Updated: 2018/11/09 15:05:16 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortwords(char *str)
{
	int i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n')
			i++;
		while (ft_isalnum(str[i]))
		{
			ft_putchar(str[i]);
			i++;
		}
		ft_putchar('\n');
	}
}
