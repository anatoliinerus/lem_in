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

int		main(void)
{
	char	*tmp;

	g_inf.ant_name = 0;
	g_inf.start10 = 1;
	g_inf.end10 = 1;
	while (get_next_line(0, &tmp) > 0 && !g_inf.stop)
	{
		if (tmp[0] == '#' && tmp[1] != '#')
			NULL;
		else if (!g_inf.num_ants && !g_inf.protect)
		{
			if (!check_ant(tmp))
				return (0);
		}
		else if (!ft_strcmp(tmp, "##end") && !g_inf.end)
			g_inf.end10 = 0;
		else if (!ft_strcmp(tmp, "##start") && !g_inf.start)
			g_inf.start10 = 0;
		else if (valid_rooms(tmp) && !g_inf.stop)
			lst_create();
		else if (valid_links(tmp, -1) && !g_inf.stop)
			NULL;
		else if (tmp && g_inf.start && g_inf.end)
			main2();
		else
		{
			write(1, "ERROR\n", 6);
			return (0);
		}
		ft_putstr(tmp);
		write(1, "\n", 1);
		ft_strdel(&tmp);
	}
	if (!g_inf.prot_start)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	if (!g_inf.main2)
		main2();
	return (0);
}

void	main2(void)
{
	g_inf.main2 = 1;
	handle_queue(0);
	if (g_inf.hui != 1)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	ft_move();
	write(1, "\nsteps: ", 8);
	ft_putnbr(g_inf.steps);
	exit(1);
}

void	print_ant(char *str, int ant)
{
	write(1, "L", 1);
	ft_putnbr(ant);
	write(1, "-", 1);
	ft_putstr(str);
	write(1, " ", 1);
}

t_lst	*find_lst(t_neighbour *neib)
{
	const char	*room = neib->room;
	t_lst		*tmp;

	tmp = g_lst;
	while (tmp && ft_strcmp(tmp->room, room) != 0)
		tmp = tmp->next;
	return (tmp);
}

void	create_queue(t_lst *list, int i, t_queue *que)
{
	t_queue *tmp;
	t_queue *new;

	if (i == 1)
		list->visited = 1;
	else
		list->visited = 0;
	if (!g_que)
	{
		g_que = ft_memalloc(sizeof(t_queue));
		g_que->lst = list;
		g_que->next = NULL;
		g_que->prev = NULL;
	}
	else
	{
		new = ft_memalloc(sizeof(t_queue));
		new->lst = list;
		new->next = NULL;
		tmp = g_que;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = que;
	}
	if (list == g_inf.end)
		g_inf.hui = 1;
}
