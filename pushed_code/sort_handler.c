/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:00:59 by decortejohn       #+#    #+#             */
/*   Updated: 2025/03/03 12:26:06 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3nbr(t_list **stack_a)
{
	t_list	*last;

	if (check_sorting(stack_a))
		return ;
	last = ft_lstlast(*stack_a);
	if (isrevsorted(*stack_a))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->content < last->content
		&& (*stack_a)->next->content < last->content)
		sa(stack_a);
	else if ((*stack_a)->content > last->content
		&& (*stack_a)->next->content < last->content)
		ra(stack_a);
	else if ((*stack_a)->content < last->content
		&& (*stack_a)->next->content > last->content)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->content > last->content
		&& (*stack_a)->next->content > last->content)
		rra(stack_a);
}

void	sort_5nbr(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	while (len--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_3nbr(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	check_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (check_sorting(stack_a))
		return ;
	if (len == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	else if (len == 3)
		sort_3nbr(stack_a);
	else if (len == 5)
		sort_5nbr(stack_a, stack_b);
	else
		quick_sort(stack_a, stack_b, ft_lstsize(*stack_a));
}
