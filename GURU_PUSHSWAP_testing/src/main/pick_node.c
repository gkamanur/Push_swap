/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:58:46 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:42:34 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/pushswap.h"

int min_max(t_list *list, char *str, int res)
{
    if (!list)
        return (-1);
    res = list->num;
    if (ft_strcmp(str, "min") == 0)
    {
        res = INT_MAX;
        while (list)
        {
            if (list->index == -1 && list->num < res)
                res = list->num;
            list = list->next;
        }
        return (res);
    }
    if (ft_strcmp(str, "max") == 0)
    {
        while (list)
        {
            if (list->num > res)
                res = list->num;
            list = list->next;
        }
        return (res);
    }
    return (-1);
}

t_list *min_node(t_list *lst)
{
    t_list  *temp;
    t_list  *curr;
    int min_val;

    temp = NULL;
    if (!lst)
        return (NULL);
    min_val = min_max(lst, "min", 0);
    if (min_val == -1)
        return (NULL);
    curr = lst;
    while (curr)
    {
        if ((curr->index == -1) && (curr->num == min_val))
        {
            temp = curr;
            break;
        }
        curr = curr->next;
    }
    return (temp);
}

t_list *indices(t_list *lst)
{
    t_list *min;
    t_list *curr;
    int index;

    index = 0;
    if (!lst)
        return(NULL) ;
    curr = lst;
    while (curr)
    {
        curr->index = -1;
        curr = curr->next;
    }
    while ((min = min_node(lst)) != NULL)
    {
        min->index = index;
        index++;
    }
    return(lst);
}
