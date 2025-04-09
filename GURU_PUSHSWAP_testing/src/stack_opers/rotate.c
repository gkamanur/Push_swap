/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:27:47 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:29:17 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_list **s_a)
{
	rotate(s_a);
	putstr_clr("ra", 1, YELLOW);
}

void	rb(t_list **s_b)
{
	rotate(s_b);
	putstr_clr("rb", 1, LIGHT_YELLOW);
}

void	rr(t_list **s_a, t_list **s_b)
{
	rotate(s_a);
	rotate(s_b);
	putstr_clr("rb", 1, DARK_YELLOW);
}
