/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:45:07 by anerus            #+#    #+#             */
/*   Updated: 2018/11/12 16:44:53 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	char		**res;
	size_t		word;
	int			j;

	i = 0;
	word = -1;
	if (s)
	{
		if (!(res = (char**)malloc(sizeof(char*) * ft_word_count(s, c) + 1)))
			return (NULL);
		while (++word < ft_word_count(s, c))
		{
			while (s[i] == c)
				i++;
			res[word] = ft_strnew(ft_word_len(s, c, i));
			j = 0;
			while (s[i] && s[i] != c)
				res[word][j++] = s[i++];
			res[word][j] = '\0';
		}
		res[word] = NULL;
		return (res);
	}
	return (NULL);
}
