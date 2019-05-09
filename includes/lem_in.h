/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:12:37 by anerus            #+#    #+#             */
/*   Updated: 2019/04/13 17:13:13 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <string.h>
# define ERROR {write(1, "ERROR\n", 6); return (0);}

typedef struct			s_info
{
	int					num_ants;
	char				*room;
	int					num;
	int					coord_x;
	int					coord_y;
	struct s_lst		*start;
	struct s_lst		*end;
	short int			start10;
	short int			end10;
}						t_info;

typedef struct		s_neighbour
{
	int					num;
	char				*room;
	struct s_neighbour	*next;
}					t_neighbour;

typedef struct		s_lst
{
	int					num;
	char				*room;
	struct s_lst		*next;
	struct s_neighbour	*links;
	short int			visited;// | start > 1 | end < 1 | visited == 1 |
	short int			blocked;
}					t_lst;

typedef struct		s_queue
{
	// char				*room;
	struct s_lst		*lst;
	struct s_queue		*next;
	struct s_queue		*prev;
}					t_queue;

typedef struct		s_ways
{
	// char				*room;
	struct s_queue		*que;
	struct s_ways		*next;
}					t_ways;

t_info					g_inf;
t_lst					*g_lst;
t_queue					*g_que;
t_ways					*g_ways;

int		valid_rooms(char *str);
void	lst_create(void);
int		valid_links(char *str);
void	links_create(char *a, char *b);
void	create_queue(t_lst *list, int i, t_queue *que);
void	handle_queue(void);
t_lst	*find_lst(t_neighbour *neib);
void	create_ways(t_queue	*que);
void	copy_que(t_ways *ways, t_queue	*que);
t_queue *clear_que(t_queue *que);

#endif