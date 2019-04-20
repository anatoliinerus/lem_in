/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:40:40 by anerus            #+#    #+#             */
/*   Updated: 2019/04/13 17:41:04 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	valid_links(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '-')
		if (!ft_isdigit(str[i]))
			return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	links_create(ft_atoi(str), ft_atoi(ft_strrchr(str, '-') + 1));
	links_create(ft_atoi(ft_strrchr(str, '-') + 1), ft_atoi(str));
	     
	      t_lst *tmp;
          t_neighbour *tmp2;

          tmp = g_lst;
          printf("|%d|\n", tmp->num);
          while (tmp)
          {
              tmp2 = tmp->links;
              if (tmp2)
              {
                 printf("%d\n", tmp2->num);
          	while (tmp2->next != NULL)    /// for print my lists
          	{
          		tmp2 = tmp2->next;
          		printf("%d\n", tmp2->num);
          	}
          	}
              if (!tmp->next)
              	break ;
          	tmp = tmp->next;
          	printf("|%d|\n", tmp->num);
          }
	return (1);
}

int	valid_rooms(char *str)
{
	int i;

	i = -1;
	if (ft_word_count(str, ' ') != 3)
		return (0);
	while (str[++i] != ' ')
		if (!ft_isascii(str[i]))
			return (0);
	while (str[++i] != ' ')
		if (!ft_isdigit(str[i]))
			return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	if (!g_inf.room)
		g_inf.room = ft_strnew(30);
	g_inf.room = ft_strncpy(g_inf.room, str, ft_strchr(str, ' ') - str);
	g_inf.coord_y = ft_atoi(ft_strchr(str, ' '));
	g_inf.coord_x = ft_atoi(ft_strrchr(str, ' '));
	return (1);
}

void	links_create(int a, int b)
{
	t_neighbour	*tmp;
	t_lst		*lmp;

	lmp = g_lst;
	while (lmp->num != b)
		lmp = lmp->next;
	if (!lmp->links)
	{
		lmp->links = ft_memalloc(sizeof(t_neighbour));
		lmp->links->num = a;
		lmp->links->next = NULL;
	}
	else
	{
		tmp = lmp->links;
		while (tmp->next != NULL)
		{
			if (tmp->num == b || tmp->num == a)
				return ;
			tmp = tmp->next;
		}
		if (tmp->num == b || tmp->num == a)
			return ;
		tmp->next = ft_memalloc(sizeof(t_neighbour));
		tmp->next->num = a;
		tmp->next->next = NULL;
	}
}

void	lst_create(void)
{
	t_lst *tmp;
	t_lst *new;

	if (!g_lst)
	{
		g_lst = ft_memalloc(sizeof(t_lst));
		g_lst->room = g_inf.room;
		g_lst->num = 1;
		g_inf.num = 1;
		g_lst->next = NULL;
	}
	else
	{
		new = ft_memalloc(sizeof(t_lst));
		g_lst->room = g_inf.room;
		new->num = ++g_inf.num;
		new->next = NULL;
		tmp = g_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	// printf("%d\n%d %d %d\n", g_inf.num_ants, g_inf.room, g_inf.coord_y, g_inf.coord_x);
	
	t_lst *test;

	test = g_lst;
	printf("%d\n", test->num);
	while (test->next != NULL)
	{
		test = test->next;
		printf("%d\n", test->num);
	}
}
