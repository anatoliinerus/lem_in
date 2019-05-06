/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:44:56 by anerus            #+#    #+#             */
/*   Updated: 2019/04/18 15:44:58 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	handle_queue(void)
{
	t_queue		*que;
	t_neighbour	*neib;

	create_queue(g_inf.start, 0);
	que = g_que;
	neib = que->lst->links;
	while (que != NULL)
	{
		neib = que->lst->links;
		if (neib)
		{
			while (neib != NULL)
			{
				if (find_lst(neib)->visited == 1)
					neib = neib->next;
				else
				{
                    create_queue(find_lst(neib), 1);
                    find_lst(neib)->visited = 1;
                    neib = neib->next;
                }
			}
			if (que->lst == g_inf.start)
				find_any_paths(que);
			que->lst->visited = 1;
		}
		que = que->next;////////////need to clear whole queue after finding first start !
	}
	// que = g_que;
	// while (que)
	// {
	// 	printf("%s\n", que->lst->room);
	// 	if (que->prev)
	// 		printf("prev = %s\n", que->prev->lst->room);
	// 	if (que->next)
	// 	printf("next = %s\n", que->next->lst->room);
	// 	que = que->next;
	// }
}

void	find_any_paths(t_queue	*que)
{
	t_ways	*tmp;
	t_ways	*new;
	// t_queue	*tmq;

	if (!g_ways)
	{
		g_ways = ft_memalloc(sizeof(t_ways));
		new = g_ways;
	}
	else
	{
		tmp = g_ways;
		new = ft_memalloc(sizeof(t_ways));
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
		// while (tmq->lst != g_inf.end)
		// {
		create_ways(new, que);
		//		tmq = tmq->prev;
		// }
}

void	create_ways(t_ways *ways, t_queue	*que) // que on start 
{
	t_queue *tmp;

	tmp = ways->que;
	if (!ways->que)
	{
		ways->que = ft_memalloc(sizeof(t_queue));
	}
	else
	{
		tmp = ways->que;
		new = ft_memalloc(sizeof(t_queue));
		new->prev = NULL;
		while (tmp-prev)
			tmp = tmp-prev;
		tmp->prev = new;
		new->next = tmp;
	}
	while(tmp->prev != g_inf.end)
	{
		tmp = tmp->prev;
	}
}

void	create_queue(t_lst *list, int i)
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
		// new->prev = NULL;
		tmp = g_que;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;///////changes
	}
}

t_lst	*find_lst(t_neighbour *neib)
{
	const char *room = neib->room;
	t_lst *tmp;

	tmp = g_lst;
	while (tmp && ft_strcmp(tmp->room, room) != 0)
		tmp = tmp->next;
	return (tmp);
}

