/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:42:40 by anerus            #+#    #+#             */
/*   Updated: 2019/05/16 14:42:43 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_main(char *tmp)
{
	if (tmp[0] == '#' && tmp[1] != '#')
		NULL;
	else if (!g_inf.num_ants && !g_inf.protect)
	{
		if (!check_ant(tmp))
			return (0);
	}
	else if (!ft_strcmp(tmp, "##end") && !g_inf.end && !g_inf.valid_links)
		g_inf.end10 = 0;
	else if (!ft_strcmp(tmp, "##start") && !g_inf.start && !g_inf.valid_links)
		g_inf.start10 = 0;
	else if (valid_rooms(tmp) && !g_inf.stop && !g_inf.valid_links)
		lst_create();
	else if (valid_links(tmp, -1, NULL) && !g_inf.stop)
	{
		g_inf.valid_links = 1;
	}
	else if (tmp && g_inf.start && g_inf.end)
		main2();
	else
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	return (1);
}
