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

typedef struct			s_info
{
	int					kek;
	short int			stop;
	short int			prot_start;
	short int			main2;
	short int			protect;
	short int			hui;
	int					num_ants;
	int					finished;
	int					ant_name;
	char				*room;
	int					num;
	int					coord_x;
	int					coord_y;
	struct s_lst		*start;
	struct s_lst		*end;
	short int			start10;
	short int			end10;
	long unsigned int	steps;
}						t_info;

typedef struct			s_neighbour
{
	int					num;
	char				*room;
	struct s_neighbour	*next;
}						t_neighbour;

typedef struct			s_lst
{
	int					num;
	int					ant;
	char				*room;
	struct s_lst		*next;
	struct s_neighbour	*links;
	short int			visited;
	short int			blocked;
}						t_lst;

typedef struct			s_queue
{
	struct s_lst		*lst;
	struct s_queue		*next;
	struct s_queue		*prev;
}						t_queue;

typedef struct			s_ways
{
	struct s_queue		*que;
	struct s_ways		*next;
	int					len;
	int					index;
}						t_ways;

t_info					g_inf;
t_lst					*g_lst;
t_queue					*g_que;
t_ways					*g_ways;

int						valid_rooms(char *str);
void					lst_create(void);
int						valid_links(char *str, int i);
void					links_create(char *a, char *b,
						t_neighbour *tmp, t_lst *lmp);
void					create_queue(t_lst *list, int i, t_queue *que);
void					handle_queue(int i);
t_lst					*find_lst(t_neighbour *neib);
void					create_ways(t_queue *que);
void					copy_que(t_ways *ways, t_queue *que);
t_queue					*clear_que();
void					ft_move(void);
void					ft_step_forward(t_ways *way);
void					ft_first_ant(t_ways *way);
int						choose_ways(int i);
t_ways					*find_way(int i);
void					print_ant(char *str, int ant);
void					ft_lstcreate2(t_lst *new);
t_queue					*handle_queue2(t_neighbour *neib, t_queue *que);
void					main2(void);
int						check_ant(char *str);
int						count(char * str);
int						check_room(char *str);
int						check_same(char *str1, char *str2);
t_queue					*handle_queue3(t_queue *que);
int						ft_main(char *tmp);

#endif
