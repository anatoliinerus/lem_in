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

void	handle_queue(int i)
{
	t_queue		*que;
	t_neighbour	*neib;

	create_queue(g_inf.start, 0, NULL);
	que = g_que;
	neib = que->lst->links;
	while (que != NULL)
	{
		neib = que->lst->links;
		if (neib)
		{
			que = handle_queue2(neib, que);
		}
		if (que)
			que = que->next;
		else
		{
			i = 1;
			que = g_que;
		}
	}
}

t_queue	*handle_queue2(t_neighbour *neib, t_queue *que)
{
	while (neib != NULL)
	{
		if (find_lst(neib)->visited == 1 ||
			find_lst(neib)->blocked == 1)
			neib = neib->next;
		else
		{
			create_queue(find_lst(neib), 1, que);
			find_lst(neib)->visited = 1;
			neib = neib->next;
		}
	}
	if (que->lst == g_inf.end)
	{
		create_ways(que);
		que = clear_que();
	}
	else
		que->lst->visited = 1;
	return (que);
}

t_queue	*clear_que(void)
{
	t_queue	*tmp;
	t_lst	*lst;

	while (g_que)
	{
		tmp = g_que;
		g_que = g_que->next;
		free(tmp);
	}
	lst = g_lst;
	while (lst->next)
	{
		lst->visited = 0;
		lst = lst->next;
	}
	lst->visited = 0;
	g_que = ft_memalloc(sizeof(t_queue));
	g_que->lst = g_inf.start;
	g_que->next = NULL;
	g_que->prev = NULL;
	return (NULL);
}

void	create_ways(t_queue *que)
{
	t_ways	*tmp;
	t_ways	*new;

	if (!g_ways)
	{
		g_ways = ft_memalloc(sizeof(t_ways));
		g_ways->index = 0;
		new = g_ways;
	}
	else
	{
		tmp = g_ways;
		new = ft_memalloc(sizeof(t_ways));
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		new->index = tmp->index + 1;
		tmp->next = new;
	}
	copy_que(new, que);
}

void	copy_que(t_ways *ways, t_queue *que)
{
	t_queue	*tmp;

	ways->len = 0;
	while (que->lst != g_inf.start)
	{
		if (!ways->que)
		{
			ways->que = ft_memalloc(sizeof(t_queue));
			tmp = ways->que;
		}
		tmp->lst = que->lst;
		tmp->next = ft_memalloc(sizeof(t_queue));
		tmp->next->prev = tmp;
		tmp = tmp->next;
		que = que->prev;
		if (que->lst != g_inf.end && que->lst != g_inf.start)
			que->lst->blocked = 1;
		ways->len++;
	}
	tmp->lst = que->lst;
	tmp->next = ft_memalloc(sizeof(t_queue));
	tmp->next->prev = tmp;
	tmp = tmp->next;
	que = que->prev;
	ways->len++;
}
