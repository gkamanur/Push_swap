/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:41:34 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:29:24 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	last = second_last->next;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **s_a)
{
	reverse_rotate(s_a);
	putstr_clr("ra", 1, GREEN);
}

void	rrb(t_list **s_b)
{
	rotate(s_b);
	putstr_clr("rb", 1, LIGHT_GREEN);
}

void	rrr(t_list **s_a, t_list **s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
	putstr_clr("rb", 1, DARK_GREEN);
}
