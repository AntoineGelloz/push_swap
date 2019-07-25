/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/25 18:31:58 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion_sort(t_stack **a, t_stack **b, int elements)
{
	int			sorted;
	//int			unsorted;
	int			largest_first;
	int			largest_size;
	t_number	*curr;
	t_number	*beg;

	//Find the largest sorted sequence
	largest_first = 0;
	largest_size = 1;
	curr = (**a).first;
	while (curr->next)
	{
		sorted = 1;
		beg = curr;
		printf("n:%d, next:%d\n", curr->n, curr->next->n);
		while (curr->next && curr->n < curr->next->n && sorted < elements)
		{
			sorted++;
			printf("n:%d, next:%d, sorted:%d\n", curr->n, curr->next->n, sorted);
			curr = curr->next;
		}
		if (sorted > largest_size)
		{
			largest_first = beg->n;
			largest_size = sorted;
		}
		printf("largest_size:%d, largest_first:%d\n", largest_size, largest_first);
		if (curr->next)
			curr = curr->next;
	}
	curr = (**a).first;
	while (curr->n != largest_first)
	{
		//ft_display_stacks(*a, *b);
		ft_putstr(" pb\n");
		sleep(1);
		*b = ft_push(a, b);
		ft_display_stacks(*a, *b);
		printf("la\n");
		curr = curr->next;
	}
	ft_display_stacks(*a, *b);
}
