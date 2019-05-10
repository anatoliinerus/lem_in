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
	int	i = 0;
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
			while (neib != NULL)
			{

				if (find_lst(neib)->visited == 1 || find_lst(neib)->blocked == 1)
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
				que = clear_que(que);
			}
			else
				que->lst->visited = 1;
		}
		if (que)
			que = que->next;////////////need to clear whole queue after finding first start !
		else
		{
			i = 1;
			que = g_que;
		}
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

t_queue *clear_que(t_queue *que)
{
	t_queue *tmp;
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

void	create_ways(t_queue	*que)
{
	t_ways	*tmp;
	t_ways	*new;
	// t_queue	*tmq;

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

		// while (g_ways->next)
		// {
		// 	printf("%s\n", g_ways->que->lst->room);
		// 	g_ways = g_ways->next;
		// }
}

void	copy_que(t_ways *ways, t_queue	*que) // que on start 
{
	t_queue *tmp;

	ways->len = 0;
	while (que->lst != g_inf.start)
	{
// printf("%s\n", que->lst->room);
// printf("%d\n", que->lst->visited);
// printf("%d\n", que->lst->blocked);
// printf("--------------------------\n\n");

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
		// tmp = add_que(que);
	}
// printf("%s\n", que->lst->room);
// printf("%d\n", que->lst->visited);
// printf("%d\n", que->lst->blocked);
// printf("--------------------------\n");

		tmp->lst = que->lst;
		tmp->next = ft_memalloc(sizeof(t_queue));
		tmp->next->prev = tmp;
		tmp = tmp->next;
		que = que->prev;
		ways->len++;
// printf("%d\n", ways->len);

	// while(tmp->lst != g_inf.end)
	// {
		// tmp = tmp->prev;
	// }
}
// t_queue	add_que(t_queue	*que)
// {
// 	t_queue	*new;

// 	new = ft_memalloc(sizeof(t_queue));
// 	new->lst = que->lst;
// }

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
		// new->prev = NULL;
		tmp = g_que;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		// new = g_que;
		// while (tmp != que)
			// tmp = tmp->next;
		new->prev = que;///////changes
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

