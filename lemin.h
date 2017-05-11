/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:15:30 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/11 19:16:31 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEMIN_H
# define LEM_IN_LEMIN_H

# include "libft/libft.h"
# include "get_next_line.h"

typedef struct		s_link
{

	struct s_li		*begin_link;
	struct s_link	*next;

}					t_link;

typedef struct		s_ways
{

	int				*n;
	long int		*status;
	int				i;
	long int		stop;
	struct s_ways	*next;

}					t_ways;

typedef struct		s_li
{
	char			flag_p;
	long int		ants;
	int				number;
	char			free;
	char			*name;
	char			type;
	struct s_li		*next;
	struct s_link	*link;

}					t_li;

t_li				*add_list();
t_link				*add_link(t_li *room);
t_ways				*add_way(int *m, int c);
int					is_ants(char *line);
void				ft_exit(int i);
int					way_len(t_ways *w);
void				get_flags(char **line, t_li *b_l);
void				make_list_start(t_li **begin_list);
void				make_list_sp(t_li **begin_list, char *line);
void				make_list_end(t_li **begin_list);
void				get_ways(t_li *begin_list, size_t k, size_t i, int *m);
void				make_num(t_li **begin_list);
int					check_for_zero(int **m, size_t i);
void				make_ways(t_li *begin_list, int *m, int c, t_ways **ways);
void				way_filter(t_ways *begin_list, size_t q);
void				sort_same_len(t_ways *b_w, size_t k, size_t n);
void				find_to_dell(int **m, size_t i, t_ways *b_w);
void				mark_way(int n, t_ways *b_w);
void				sort_and_clean_ways(t_ways *ways);
long int			on_start(t_ways *b_w, long int ants, long int *k);
void				move_ants(t_ways *b_w, t_li *b_l, long int stop, int i);
size_t				list_len(t_li *b_l);
char				*get_room(t_li *b_l, int i);
char				*get_room_1(char *line, t_li *begin_list);
char				*get_room_2(char *line, t_li *begin_list, char *r1);
void				free_all(t_li *b_l, t_ways*b_w, t_li *next);
void				free_matrix(int **m, int i);

#endif
