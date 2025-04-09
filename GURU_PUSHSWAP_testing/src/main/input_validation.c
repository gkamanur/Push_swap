/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:00:32 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:42:22 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/pushswap.h"

void	load_logic(char *str, t_list **node)
{
	long int	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		putstr_clr("👊👊👊 input exceeds the limits..watching 👁️ 👁️", 1, YELLOW);
		exit(-1);
	}
	*node = append_node(num, *node);
}

t_list	*check_input(int ac, char **av, t_list *list)
{
	char		**arg;
	int			i;

	arg = NULL;
	if (ac == 2)
	{
		i = 0;
		arg = ft_split(av[1], ' ');
		if (!arg)
			return (NULL);
		while (arg[i])
			load_logic(arg[i++], &list);
		free_split(arg);
		return (list);
	}
	if (ac > 2)
	{
		i = 1;
		while (av[i])
			load_logic(av[i++], &list);
		return (list);
	}
    return (list);
}
