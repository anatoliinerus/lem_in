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

	create_queue(g_inf.start);
	que = g_que;
	neib = que->lst->links;
	while (que != NULL)
	{
		neib = que->lst->links;
		if (neib)
		{
			while (neib != NULL)
			{
				create_queue(find_lst(neib));
				printf("in:%s\n", neib->room);
				neib = neib->next;
			}
			// create_queue(find_lst(neib));
			// printf("out:%s\n", neib->room);
		}
		que = que->next;
	}
}

void	create_queue(t_lst *list)
{
	t_queue *tmp;
	t_queue *new;

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
		new->prev = NULL;
		tmp = g_que;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	// list->visited
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

