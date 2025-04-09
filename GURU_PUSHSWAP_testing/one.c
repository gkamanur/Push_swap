#include "include/pushswap.h"

void	load_logic(char *str, t_list **node)
{
	long int	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		putstr_clr("👊👊👊 input exceeds the limits..watching 👁️👁️", 1, YELLOW);
		return ;
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
		{
			load_logic(arg[i], &list);
			i++;
		}
		free_split(arg, i + 1);
		return (list);
	}
	if (ac > 2)
	{
		i = 1;
		while (av[i])
		{
			load_logic(av[i], &list);
			i++;
		}
		return (list);
	}
    return (list);
}
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
            if (list->num < res)
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

void print_stack(t_list *lst)
{
    while (lst)
    {
        printf ("[%li, %i, %i]", lst->num, lst->index, lst->level);
        lst = lst->next;
    }
    write (1, "\n", 1);
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
    indices(s_a);
    print_stack(s_a);
    free_list(&s_a);
	return (0);
}