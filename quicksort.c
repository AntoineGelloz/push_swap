/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/30 14:17:58 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_number(t_stack **s, int index)
{
	t_number	*curr;

	curr = (**s).first;
	while (curr->next && curr->index != index)
		curr = curr->next;	
	return (curr->n);
}

void	ft_push_number(t_stack **a, t_stack **b, int i)
{
	printf("i:%d first:%d, index:%d\n", i, (**a).first->n, (**a).first->index);
	while ((**a).first->index != i)
	{
		ft_rotate(a, 'a', 1);
		printf("first:%d, index:%d\n", (**a).first->n, (**a).first->index);
	}
	ft_display_stacks(*a, *b);
	ft_push(a, b, 'b', 1);
}

int		ft_partition(t_stack **a, t_stack **b, int start_index, int end_index)
{
	int pivot;
	int left_index;
	int right_index;

	pivot = ft_get_number(a, end_index);
	left_index = start_index;
	right_index = end_index - 1;
	while (left_index <= right_index)
	{
		printf("left:%d, right:%d\n", left_index, right_index);
		while (left_index <= end_index && ft_get_number(a, left_index) < pivot)
			left_index++;
		while (right_index >= start_index && ft_get_number(a, right_index) >= pivot)
			right_index--;
		if (left_index < right_index)
		{
			ft_push_number(a, b, left_index);
			ft_display_stacks(*a, *b);
			ft_putchar('\n');
			end_index--;
		}
		else
			ft_push_number(a, b, end_index);
	}
	return (left_index);
}

void	ft_quicksort_sublist(t_stack **a, t_stack **b, int start, int end)
{
	int pivot;

	if (start >= end)
		return ;
	pivot = ft_partition(a, b, start, end);
	//ft_quicksort_sublist(a, b, start, pivot - 1);
	//ft_quicksort_sublist(a, b, pivot + 1, end);
}

void	ft_quicksort(t_stack **a, t_stack **b, int elements)
{
	ft_putstr("Init : ");
	ft_display_stacks(*a, *b);
	ft_putchar('\n');
	ft_quicksort_sublist(a, b, 0, elements - 1);
}
