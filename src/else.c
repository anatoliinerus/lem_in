/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:00 by anerus            #+#    #+#             */
/*   Updated: 2019/05/15 14:56:04 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_ant(char *tmp)
{
	int	i;

	i = -1;
	g_inf.protect = 1;
	while (tmp[++i])
		if (ft_isdigit(tmp[i]) != 1)
		{
			write(1, "ERROR\n", 6);
			return (0);
		}
	if ((g_inf.num_ants = ft_atoi(tmp)) < 1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	return (1);
}

int	count(char *str)
{
	int					i;
	unsigned short int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '-')
			count++;
	if (count != 1)
		return (1);
	else
		return (0);
}

int	check_room(char *str)
{
	int		i;
	t_lst	*tmp;

	i = -1;
	tmp = g_lst;
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->room))
			g_inf.stop = 1;
		tmp = tmp->next;
	}
	return (0);
}

int	check_same(char *str1, char *str2)
{
	t_lst	*tmp;
	int		a;
	int		b;

	a = 0;
	b = 0;
	tmp = g_lst;
	while (tmp)
	{
		if (!ft_strcmp(str1, tmp->room))
			a++;
		else if (!ft_strcmp(str2, tmp->room))
			b++;
		tmp = tmp->next;
	}
	if (a && b)
		return (1);
	return (0);
}

t_queue	*handle_queue3(t_queue *que)
{
	if (que->prev->lst == g_inf.start && g_inf.finished < g_inf.kek)
	{
		g_inf.finished++;
		g_inf.num_ants--;
		g_inf.steps++;
		print_ant(g_inf.start->room, ++g_inf.ant_name);
		write(1, "\n", 1);
		if (g_inf.num_ants == 0)
		{
			write(1, "\nsteps: ", 8);
			ft_putnbr(g_inf.steps);
			exit(1);
		}
	}
	return (que);
}

