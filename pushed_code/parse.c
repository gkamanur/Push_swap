/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:45:17 by gkamanur          #+#    #+#             */
/*   Updated: 2025/03/04 08:56:17 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

void	append_node(t_list **stack, int nbr)
{
	t_list	*node;
	t_list	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->content = nbr;
	node->flag = 0;
	node->index = -1;
	if (*stack == NULL)
	{
		*stack = node;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = node;
	}
}

void	stack_init(t_list **a, char **argv, int ac)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, ac);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, ac);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, ac);
		append_node(a, (int)nbr);
		++i;
	}
	add_index(*a);
	if (ac == 2)
		free_matrix(argv);
}
