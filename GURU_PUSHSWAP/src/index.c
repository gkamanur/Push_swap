/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:00:35 by decortejohn       #+#    #+#             */
/*   Updated: 2025/02/24 16:24:15 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	index_replace(t_list *lst, int n, int to)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content == n)
			break ;
		tmp = tmp->next;
	}
	tmp->index = to;
}

int	min_nbr(t_list *lst)
{
	t_list		*tmp;
	long int	min;

	min = LONG_MAX;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	add_index(t_list *lst)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len)
	{
		min = min_nbr(lst);
		index_replace(lst, min, i);
		i++;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
