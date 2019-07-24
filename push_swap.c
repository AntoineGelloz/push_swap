/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/24 17:59:12 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion_sort(t_stack **a, t_stack **b, int elements)
{
	int			sorted;
	int			unsorted;
	t_number	*curr;

	sorted = 0;
	curr = (**a).first;
	while (curr->next && curr->n < curr->next->n && sorted < elements)
	{
		printf("n:%d, next:%d\n", curr->n, curr->next->n);
		sorted++;
		curr = curr->next;
	}
	unsorted = elements - sorted;
	printf("el:%d, unsorted:%d\n", elements, unsorted);
	while (sorted && unsorted--)
	{
		ft_putstr("rra\n");
		*a = ft_reverse_rotate(a);
	}
}

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	if (!(a = malloc(sizeof(*a))) || !(b = malloc(sizeof(*b))))
		return (0);
	a->first = NULL;
	b->first = NULL;
	if (ac < 2 || !ft_fill_a(&a, ac, av))
		return (0);
	ft_insertion_sort(&a, &b, ac - 1);
	ft_display_stacks(a, b);
	//ft_selection_sort(&a, &b, ac);
	ft_delete_stacks(a, b);
	return (0);
}
