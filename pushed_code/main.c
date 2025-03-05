/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:23:48 by decortejohn       #+#    #+#             */
/*   Updated: 2025/03/04 09:05:04 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdbool.h>
#include <stdio.h>

void	print_stack(t_list *stack, char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("[%li, %i, %i] ", stack->content, stack->index, stack->flag);
		stack = stack->next;
	}
	printf("\n");
}

int	ft_check(t_list *lst, int n, char *nbr)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+') && ft_isdigit(nbr[i + 1])
					&& (i == 0 || !ft_isdigit(nbr[i - 1])))
				|| ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if (tmp->content == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*ft_init(char **ag, int ac)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	long	nbr;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (ag[i])
	{
		nbr = ft_atoi(ag[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_check(res, nbr, ag[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&res, tmp);
		tmp->index = -1;
		i++;
	}
	return (res);
}

void	split(int ac, char **ag, char ***args, int *free_args)
{
	if (ac == 2)
	{
		*args = ft_split(ag[1], ' ');
		*free_args = 1;
	}
	else
	{
		*args = ag;
		*free_args = 0;
	}
}

int	main(int ac, char **ag)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !ag[1][0]))
		return (1);
	if (ac == 2)
		args = ft_split(ag[1], ' ');
	else
		args = ag + 1;
	stack_init(&stack_a, args, ac);
	check_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
