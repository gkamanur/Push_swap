/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:19:09 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:42:30 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/pushswap.h"
#include <stdio.h>

void print_stack(t_list *lst)
{
    t_list *curr = lst;
    if (!lst)
    {
        write(1, "Empty stack\n", 12);
        return;
    }
    while (curr)
    {
        printf ("[%li, %i, %i]", curr->num, curr->index, curr->level);
        curr = curr->next;
        if (curr)
            printf(" -> ");
    }
    printf("\n");
}

int	main(int ac, char **av)
{
    t_list *s_a;
    
    s_a = NULL;
    if (ac == 1)
    {
		putstr_clr("🤪 🤪 🤪 Give Proper inputs!!!", 1, RED);
        return(0) ;
    }
    s_a = check_input(ac, av, s_a);
    if (!s_a)
    {
        putstr_clr("Error: Invalid input or allocation failed", 1, RED);
        return (1);
    }
    printf("Before indices:\n");
    print_stack(s_a);
    indices(s_a);
    printf("after indices:\n");
    print_stack(s_a);
    free_list(&s_a);
	return (0);
}
