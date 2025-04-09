/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:59:42 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:30:11 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (!stack_b || !*stack_b)
		return ;
	aux = *stack_b;
	*stack_b = aux->next;
	aux->next = *stack_a;
	*stack_a = aux;
	putstr_clr("pa", 1, VIOLET);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (!stack_a || !*stack_a)
		return ;
	aux = *stack_a;
	*stack_a = aux->next;
	aux->next = *stack_b;
	*stack_b = aux;
	putstr_clr("pb", 1, VIOLET);
}
