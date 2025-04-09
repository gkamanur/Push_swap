/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:01:42 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:42:26 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/pushswap.h"

t_list *newnode (long int data)
{
    t_list *node;
    
    if (data > INT_MAX || data < INT_MIN)
        return (NULL);
    node = malloc (sizeof(t_list));
    if (!node)
        return  (NULL);
    node->num = data;
    node->level = 0;
    node->index = -1;
    node->next = NULL;
    return (node);
}

t_list *append_node (long int data, t_list *node)
{
    t_list *new;
    t_list *curr;
    
    new = newnode(data);
    
    if (!new)
       return (node);
    if (!node)
        return(new);
    curr = node;
    while (curr->next)
        curr = curr->next;
    curr->next = new;
    return(node);  
}

int     lst_size(t_list *lst)
{
    int len;
    t_list *curr;

    if (!lst)
        return (0);
    curr = lst;
    len = 0;
    while (curr)
    {
        len++;
        curr = curr->next;
    }
    return (len);
}

void    free_list(t_list **lst)
{
    t_list *curr;
    if (!lst || !*lst)
        return ;
    while (*lst)
    {
        curr = *lst;
        *lst = (*lst)->next;
        free(curr);
    }
} 
