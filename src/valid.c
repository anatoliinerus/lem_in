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
	char *argv1;

	i = -1;
	if (ft_word_count(str, '-') != 2)
		return (0);
	while (str[++i] != '-')
		if (!ft_isascii(str[i]))
			return (0);
	while (str[++i])
		if (!ft_isascii(str[i]))
			return (0);
	argv1 = ft_strsub(str, 0, ft_strchr(str, '-') - str);
	if (!ft_strcmp(argv1, ft_strchr(str, '-') + 1))
		return (0);
	links_create(argv1, ft_strchr(str, '-') + 1);
	links_create(ft_strchr(str, '-') + 1, argv1);
	ft_strdel(&argv1);



	     
	//       t_lst *tmp;
 //          t_neighbour *tmp2;
 //          static int kek = -1;
 //          tmp = g_lst;
 //          // printf("|%d|\n", tmp->num);
 //          printf("\n--------------------%d\n", ++kek);
 //          printf("|%s|\n", tmp->room);
 //          while (tmp)
 //          {
 //              tmp2 = tmp->links;
 //              if (tmp2)
 //              {
 //                 // printf("%d\n", tmp2->num);
 //                 printf("%s\n", tmp2->room);
 //          	while (tmp2->next != NULL)    /// for print my lists
 //          	{
 //          		tmp2 = tmp2->next;
 //          		printf("%s\n", tmp2->room);
 //          	}
 //          	}
 //          	if (!tmp->next)
 //              	break ;
 //          	tmp = tmp->next;
 //          	printf("|%s|\n", tmp->room);
 //          }
 //          // printf("start: %s end: %s\n",  g_inf.start->room, g_inf.end->room);
 //          printf("\n--------------------\n");
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
	ft_strclr(g_inf.room);
	g_inf.room = strncpy(g_inf.room, str, strchr(str, ' ') - str);
	g_inf.coord_y = ft_atoi(ft_strchr(str, ' '));
	g_inf.coord_x = ft_atoi(ft_strrchr(str, ' '));
	return (1);
}

void	links_create(char *a, char *b)
{
	t_neighbour	*tmp;
	t_lst		*lmp;

	lmp = g_lst;
	while (lmp && !ft_strequ(lmp->room, b))
		lmp = lmp->next;
	if (lmp && !lmp->links)
	{
		lmp->links = ft_memalloc(sizeof(t_neighbour));
		lmp->links->room = ft_strdup(a);
		lmp->links->next = NULL;
	}
	else if (lmp)
	{
		tmp = lmp->links;
		while (tmp->next != NULL)
		{
			if (!ft_strcmp(tmp->room, b) || !ft_strcmp(tmp->room, a))
				return ;
			tmp = tmp->next;
		}
		if (!ft_strcmp(tmp->room, b) || !ft_strcmp(tmp->room, a))
			return ;
		tmp->next = ft_memalloc(sizeof(t_neighbour));
		tmp->next->room = ft_strdup(a);
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
		g_lst->room = ft_strdup(g_inf.room);
		g_lst->num = 0;
		g_inf.num = 0;
		g_lst->next = NULL;
		new = g_lst;
	}
	else
	{
		new = ft_memalloc(sizeof(t_lst));
		new->room = ft_strdup(g_inf.room);
		new->num = ++g_inf.num;
		new->next = NULL;
		tmp = g_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (!g_inf.start10)
		g_inf.start = new;
	else if (!g_inf.end10)
			g_inf.end = new;
	g_inf.start10 = 1;//right now don t use
	g_inf.end10 = 1;
	if (!g_inf.room)
		ft_strdel(&g_inf.room);
	// printf("|%s| %d %d\n", g_inf.room, g_inf.coord_y, g_inf.coord_x);
	
	// t_lst *test;

	// test = g_lst;
	// printf("%s\n", test->room);
	// while (test->next != NULL)
	// {
	// 	test = test->next;
	// 	printf("%s\n", test->room);
	// }
}
