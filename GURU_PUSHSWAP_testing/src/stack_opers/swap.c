/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:49:24 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:37:02 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **s_a)
{
	swap(s_a);
	putstr_clr("sa", 1, ORANGE);
}

void	sb(t_list **s_b)
{
	swap(s_b);
	putstr_clr("sa", 1, LIGHT_ORANGE);
}

void	ss(t_list **s_a, t_list **s_b)
{
	swap(s_a);
	swap(s_b);
	putstr_clr("ss", 1, DARK_ORANGE);
}
