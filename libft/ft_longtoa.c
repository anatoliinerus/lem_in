/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:15:10 by anerus            #+#    #+#             */
/*   Updated: 2019/02/04 16:15:27 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length(unsigned long n)
{
	int				len;
	unsigned long	tmp;

	len = 0;
	tmp = n;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

char			*ft_longtoa_u(unsigned long n)
{
	unsigned long	tmp;
	int				len;
	char			*str;

	tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	len = length(tmp);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (tmp)
	{
		str[--len] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (str);
}
