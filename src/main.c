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

	while (get_next_line(0, &tmp) > 0)
	{
		if (!g_inf.num_ants && (g_inf.num_ants = ft_atoi(tmp)) < 1)
			ERROR
		else if (valid_rooms(tmp))
			lst_create();
		else if (valid_links(tmp))
			printf("work\n");
        ft_strdel(&tmp);
    }
	return 0;
}
