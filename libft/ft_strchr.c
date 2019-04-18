/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:55:56 by anerus            #+#    #+#             */
/*   Updated: 2018/10/29 18:46:20 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = -1;
	while (++i < ft_strlen(s) + 1)
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (NULL);
}
