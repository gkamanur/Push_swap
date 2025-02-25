/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:01:53 by decortejohn       #+#    #+#             */
/*   Updated: 2025/02/25 11:55:11 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_r(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

void	ra(t_list **stack1)
{
	ft_r(stack1);
	// write(1, "ra\n", 3);
	printf(COLOR_BOLD_SLOW_BLINKING_RED "ra:" COLOR_OFF);
	print_stack(*stack1, "a_flag_stack1");
	// print_stack(*stack2, "a_flag_stack2");
}

void	rb(t_list **stack2)
{
	ft_r(stack2);
	// write(1, "rb\n", 3);
	printf(COLOR_BOLD_SLOW_BLINKING_RED "rb:" COLOR_OFF);
	// print_stack(*stack1, "a_flag_stack1");
	print_stack(*stack2, "a_flag_stack2");
}

void	rr(t_list **stack1, t_list **stack2)
{
	ft_r(stack1);
	ft_r(stack2);
	// write(1, "rr\n", 3);
	printf(COLOR_BOLD_SLOW_BLINKING_RED "rr:" COLOR_OFF);
	print_stack(*stack1, "a_flag_stack1");
	print_stack(*stack2, "a_flag_stack2");
}
