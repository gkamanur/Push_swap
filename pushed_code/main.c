/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:23:48 by decortejohn       #+#    #+#             */
/*   Updated: 2025/02/27 13:50:02 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void	print_stack(t_list *stack, char *name)
// {
// 	printf("%s: ", name);
// 	while (stack)
// 	{
// 		printf("[%li] ", stack->content);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

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

void	check_stacks(t_swap **tab, int *free_args, char ***args)
{
	if ((*tab)->stack_a == NULL)
	{
		if (*free_args)
			free_args_array(*args);
		free(*tab);
		return ;
	}
	(*tab)->stack_b = NULL;
}

int	main(int ac, char **ag)
{
	t_swap	*tab;
	char	**args;
	int		free_args;

	if (ac == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	split(ac, ag, &args, &free_args);
	tab->stack_a = ft_init(args, ac);
	check_stacks(&tab, &free_args, &args);
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	check_sort(tab);
	free_swap(tab);
	if (free_args)
		free_args_array(args);
	return (0);
}
