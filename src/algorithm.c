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
	// g_que = ft_memalloc(sizeof(t_queue));
	t_queue		*que;

	create_queue(NULL);
	que = g_que;

	// printf("%s\n", que->lst->room);
	que->lst = g_inf.start;
	while (que->lst->links)
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
}
