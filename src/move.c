/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 04:27:17 by anerus            #+#    #+#             */
/*   Updated: 2019/05/10 04:27:18 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_move(void)
{
	int		i;
	int		num;

	num = g_inf.num_ants;
	g_inf.ant_name = 0;
	g_inf.steps = 0;
	// t_ways	*tmp;

	// tmp = g_ways;
	while (g_inf.finished < num)
	{
		if (g_inf.num_ants > 0)
		{
			i = -1;
			while (find_way(++i))
				if (g_inf.num_ants > choose_ways(i))
				{
					ft_first_ant(find_way(i));
					// if (g_inf.num_ants != num)
					// 	ft_step_forward(find_way(i));
					g_inf.num_ants--;
				}
					// printf("%d\n", g_inf.finished);
		}
		i = -1;
					write(1, "\n", 1);
					g_inf.steps++;
		while (find_way(++i))
		{
			ft_step_forward(find_way(i));
		}
			// write(1, "\n", 1);

	}
}

void	ft_step_forward(t_ways *way)
{
	t_queue	*tmp;

	tmp = way->que;
	// printf("--------------------------\n");
	while (tmp->lst != g_inf.start)
	{
			// printf("%s %d\n", tmp->next->lst->room, tmp->next->lst->ant);

			// printf("%s %d\n", tmp->lst->room, tmp->lst->ant);

		if (tmp->next->lst->ant != 0)
		{
			if (tmp->lst == g_inf.end)
			{
				g_inf.finished++;
				print_ant(tmp->lst->room, tmp->next->lst->ant);
			}
			else
			{
				// if (tmp->next->lst != g_inf.start)
				tmp->lst->ant = tmp->next->lst->ant;
				print_ant(tmp->lst->room, tmp->lst->ant);

			}
			tmp->next->lst->ant = 0;
			// g_inf.steps++;
		}
		tmp = tmp->next;
	}
	// printf("--------------------------\n");

}

void	ft_first_ant(t_ways	*way)
{
	t_queue	*tmp;

	tmp = way->que;
	while (tmp->next->lst != g_inf.start)
		tmp = tmp->next;
	tmp->lst->ant = ++g_inf.ant_name ;
	print_ant(tmp->lst->room, tmp->lst->ant);
	// g_inf.steps++;
}

int  choose_ways(int i)
{
 int  counter;
 int  count;

 count = 0;
 counter = -1;
 while (++counter < i)
  count += find_way(i)->len - find_way(counter)->len;
 return (count);
}

t_ways	*find_way(int	i)
{
	t_ways	*tmp;

	tmp = g_ways;
	while (tmp && tmp->index != i)
		tmp = tmp->next;
	return (tmp);
}

void	print_ant(char *str, int ant)
{
	write(1, "L", 1);
	ft_putnbr(ant);
	write(1, "-", 1);
	ft_putstr(str);
	write(1, " ", 1);


}
