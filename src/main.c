/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:11:08 by anerus            #+#    #+#             */
/*   Updated: 2019/04/13 17:11:11 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	char *tmp;

	g_inf.start10 = 1;
	g_inf.end10 = 1;
	while (get_next_line(0, &tmp) > 0)
	{
		if (!g_inf.num_ants && (g_inf.num_ants = ft_atoi(tmp)) < 1)
			ERROR
		else if (!ft_strcmp(tmp, "##end") && !g_inf.end)
			g_inf.end10 = 0;
		else if (!ft_strcmp(tmp, "##start") && !g_inf.start)
			g_inf.start10 = 0;
		else if (valid_rooms(tmp))
			lst_create();
		else if (valid_links(tmp))
			NULL;
         // else if (tmp && !ft_strcmp(tmp, "break"))///LEAKS
         //     break;
        ft_strdel(&tmp);

    }
			// printf("test\n");

    handle_queue();
	return (0);
}
