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
	short int			start;
	short int			end;
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
	short int			start;
	short int			end;
	short int			visited;// | start > 1 | end < 1 | visited == 1 |
}					t_lst;

t_info					g_inf;
t_lst					*g_lst;

int		valid_rooms(char *str);
void	lst_create(void);
int		valid_links(char *str);
void	links_create(char *a, char *b);

#endif