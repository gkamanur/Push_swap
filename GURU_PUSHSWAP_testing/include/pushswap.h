/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:55:14 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:38:30 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "colors.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long int		num;
	int				index;
	int				level;
	struct s_list	*next;
}					t_list;

typedef struct s_value
{
	int				min;
	int				max;
	int				median;
}					value;
// Load Arguments to stack
void				putstr_fd(char *str, int fd);
void				putstr_clr(char *str, int fd, char *clr);
t_list				*newnode(long int data);
t_list				*append_node(long int data, t_list *node);
int					ft_strcmp(const char *s1, const char *s2);
int					min_max(t_list *list, char *str, int res);
t_list				*min_node(t_list *lst);
int					lst_size(t_list *lst);
void				free_list(t_list **lst);
long int			ft_atoi(const char *str);
t_list				*indices(t_list *lst);
void				free_split(char **result);
char				**ft_split(char const *s, char c);
t_list				*check_input(int ac, char **av, t_list *list);
// Stack operations
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				rra(t_list **s_a);
void				rrb(t_list **s_b);
void				rrr(t_list **s_a, t_list **s_b);
void				ra(t_list **s_a);
void				rb(t_list **s_b);
void				rr(t_list **s_a, t_list **s_b);
void				sa(t_list **s_a);
void				sb(t_list **s_b);
void				ss(t_list **s_a, t_list **s_b);

#endif