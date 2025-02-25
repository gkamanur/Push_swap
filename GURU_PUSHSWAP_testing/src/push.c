/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:34:08 by decortejohn       #+#    #+#             */
/*   Updated: 2025/02/25 11:51:15 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_list **stack1, t_list **stack2)
{
	t_list	*push_b;

	if (!*stack2)
		return ;
	push_b = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = push_b;
	// ft_putstr_fd("pa:", 1);
	printf(COLOR_BOLD_SLOW_BLINKING_RED "pa:" COLOR_OFF);
	print_stack(*stack1, "a_flag_stack1");
	print_stack(*stack2, "a_flag_stack2");
}

void	pb(t_list **stack1, t_list **stack2)
{
	t_list	*push_a;

	if (!*stack1)
		return ;
	push_a = (*stack1)->next;
	(*stack1)->next = *stack2;
	*stack2 = *stack1;
	*stack1 = push_a;
	// ft_putstr_fd("pb\n", 1);
	printf(COLOR_BOLD_SLOW_BLINKING_RED "pb:" COLOR_OFF);
	print_stack(*stack1, "a_flag_stack1");
	print_stack(*stack2, "a_flag_stack2");
}
