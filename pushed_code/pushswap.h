/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:44:49 by jdecorte          #+#    #+#             */
/*   Updated: 2025/03/04 08:57:11 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}		t_push;

// typedef struct s_swap
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	int		asize;
// 	int		bsize;
// }			t_swap;

void	print_stack(t_list *stack, char *name);
void	check_sort(t_list **stack_a, t_list **stack_b);
int		check_sorting(t_list **stack1);
int		check_sorting_a(t_list **stack1, int count);
t_list	*find_min_lst(t_list **stack);
t_list	*find_max_lst(t_list **stack);
int		isrevsorted(t_list *stack_a);
void	free_args_array(char **args);
void	free_matrix(char **argv);
void	free_stack(t_list **stack);
void	stack_init(t_list **a, char **argv, int flag_argc_2);
void	error_free(t_list **a, char **argv, int flag_argc_2);
int		error_repetition(t_list *a, int nbr);
int		error_syntax(char *str_nbr);

void	pa(t_list **stack1, t_list **stack2);
void	pb(t_list **stack1, t_list **stack2);
void	ra(t_list **stack1);
void	rb(t_list **stack2);
void	rr(t_list **stack1, t_list **stack2);
void	sa(t_list **stack1);
void	sb(t_list **stack2);
void	ss(t_list **stack1, t_list **stack2);
void	rrb(t_list **stack2);
void	rra(t_list **stack1);

void	add_index(t_list *lst);
void	quick_sort(t_list **stack1, t_list **stack2, int count);
#endif