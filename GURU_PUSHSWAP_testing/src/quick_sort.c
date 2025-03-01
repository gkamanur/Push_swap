/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:38:33 by decortejohn       #+#    #+#             */
/*   Updated: 2025/02/28 17:45:22 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	begin_sorting(t_list **stack1, t_list **stack2, t_push *push, int count)
{
	int	i;

	i = -1;
	printf(COLOR_CYAN "Starting begin_sort ::min=%i: max=%i: mid=%i: flag=%i\n" COLOR_OFF,push->next,push->max,push->mid,push->flag);
	while (++i < count)
	{
		if ((*stack1)->index <= push->mid)
			pb(stack1, stack2);
		else
			ra(stack1);
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	find_next(t_list **stack1, t_list **stack2, t_push *push)
{
	int i = 0;
	
	printf(COLOR_CYAN "Starting find_next ::min=%i: max=%i: mid=%i: flag=%i\n" COLOR_OFF,push->next,push->max,push->mid,push->flag);
	if (ft_lstsize(*stack2) > 0 && ((*stack2)->index == push->next))
		pa(stack1, stack2);
	else if ((*stack1)->index == push->next)
	{
		(*stack1)->flag = -1;
		ra(stack1);
		push->next++;
	}
	else if ((ft_lstsize(*stack2)) > 2
		&& ft_lstlast(*stack2)->index == push->next)
		rrb(stack2);
	else if ((*stack1)->next->index == push->next)
		sa(stack1);
	else if ((ft_lstsize(*stack1)) > 1 && ((*stack1)->next->index == push->next)
		&& ((*stack2)->next->index == push->next + 1))
		ss(stack1, stack2);
	else
	{
		printf(COLOR_BOLD_YELLOW  "end find_next:%i\n" COLOR_OFF,i);
		printf(COLOR_CYAN "ending find_next ::min=%i: max=%i: mid=%i: flag=%i\n" COLOR_OFF ,push->next,push->max,push->mid,push->flag);
		print_stack(*stack1, "a_flag_stack1");
		print_stack(*stack2, "a_flag_stack2");
		return ;
	}
	printf(COLOR_BOLD_YELLOW  "In find_next:%i\n" COLOR_OFF,++i);
	print_stack(*stack1, "a_flag_stack1");
	print_stack(*stack2, "a_flag_stack2");
	find_next(stack1, stack2, push);
	
}

void	quick_a(t_list **stack1, t_list **stack2, t_push *push)
{
	int	count_b;
	int	i;
	// int n = 0;

	i = -1;
	count_b = ft_lstsize(*stack2);
	printf(COLOR_BOLD_BLUE "\nFunction quick_a\n" COLOR_OFF);
	printf("startting Quick_a ::min=%i: max=%i: mid=%i: flag=%i\n",push->next,push->max,push->mid,push->flag);
	while (ft_lstsize(*stack2) && ++i < count_b)
	{
		if ((*stack2)->index == push->next)
		{
			find_next(stack1, stack2, push);
		}
		else if ((*stack2)->index >= push->mid)
		{
			(*stack2)->flag = push->flag;
			pa(stack1, stack2);
		}
		else if ((*stack2)->index < push->mid)
			rb(stack2);
	}
	print_stack(*stack1, "a_flag_stack1");
	print_stack(*stack2, "a_flag_stack2");
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
	printf("ending Quick_a ::min=%i: max=%i: mid=%i: flag=%i\n",push->next,push->max,push->mid,push->flag);
}

void	quick_b(t_list **stack1, t_list **stack2, t_push *push)
{
	int	now_flag;
	int count = 0;
	
	now_flag = (*stack1)->flag;
	printf(COLOR_BOLD_BLUE "\nFunction quick_b, now_flag=%i\n" COLOR_OFF,now_flag);
	printf("startting Quick_b ::min=%i: max=%i: mid=%i: flag=%i\n",push->next,push->max,push->mid,push->flag);
	printf("Before-----stack_flag:%i   now_flag:%i\n", (*stack1)->flag, now_flag);
	while ((*stack1)->flag == now_flag)
	{
		if ((*stack1)->index != push->next)
		{
			pb(stack1, stack2);
		}
		find_next(stack1, stack2, push);
		printf("++++++++++++++++++++++++++stack_flag:%i   now_flag:%i\n", (*stack1)->flag, now_flag);
		count++;
	}
	printf("after---stack_flag:%i   now_flag:%i\n", (*stack1)->flag, now_flag);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++count :%i***\n", count);
	if (ft_lstsize(*stack2))
		push->max = (find_max_lst(stack2))->index;
	push->mid = (push->max - push->next) / 2 + push->next;
	printf("ending Quick_b ::min=%i: max=%i: mid=%i: flag=%i\n",push->next,push->max,push->mid,push->flag);
}

void	quick_sort(t_list **stack1, t_list **stack2, int count)
{
	t_push	push;

	push.next = find_min_lst(stack1)->index;
	push.max = find_max_lst(stack1)->index;
	push.mid = push.max / 2 + push.next;
	push.flag = 0;
	printf(COLOR_BOLD_BLUE "before begin_sorting\n" COLOR_OFF);
	print_stack(*stack1, "a_flag_stack1");
	print_stack(*stack2, "a_flag_stack2");
	begin_sorting(stack1, stack2, &push, count);
	printf(COLOR_BOLD_BLUE "After begin_sorting\n" COLOR_OFF);
	print_stack(*stack1, "a_flag_stack1");
	print_stack(*stack2, "a_flag_stack2");
	while (!(check_sorting_a(stack1, count)))
	{
		if (ft_lstsize(*stack2) == 0)
		{
			quick_b(stack1, stack2, &push);
			printf("after quick_b\n");
			print_stack(*stack1, "a_flag_stack1");
			print_stack(*stack2, "a_flag_stack2");
		}
		else
		{
			quick_a(stack1, stack2, &push);
			printf("after quick_a\n");
			print_stack(*stack1, "a_flag_stack1");
			print_stack(*stack2, "a_flag_stack2");
		}
	}
}
