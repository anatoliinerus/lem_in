/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:21:47 by anerus            #+#    #+#             */
/*   Updated: 2019/02/06 22:21:49 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length_u(uintmax_t n, int base)
{
	int				len;
	unsigned long	tmp;

	len = 0;
	tmp = n;
	while (tmp)
	{
		len++;
		tmp /= base;
	}
	return (len);
}

char			*ft_itoa_base(unsigned long n, int base)
{
	unsigned long	tmp;
	int				len;
	char			*str;
	char			*base_str;

	tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	base_str = "0123456789abcdef";
	len = length_u(tmp, base);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (tmp)
	{
		str[--len] = base_str[tmp % base];
		tmp /= base;
	}
	return (str);
}
