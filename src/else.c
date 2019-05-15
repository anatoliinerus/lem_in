/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:00 by anerus            #+#    #+#             */
/*   Updated: 2019/05/15 14:56:04 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_ant(char *tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		if (ft_isdigit(tmp[i]) != 1)
		{
			write(1, "ERROR\n", 6);
			return (0);
		}
	if ((g_inf.num_ants = ft_atoi(tmp)) < 1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	return(1);
}
