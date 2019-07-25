/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/25 18:51:13 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sorted(t_stack *a)
{
	t_number	*curr;

	curr = a->first;
	while (curr->next)
	{
		if (curr->n > curr->next->n)
			break ;
		curr = curr->next;
	}
	if (!curr->next)
		return (1);
	return (0);
}

void	ft_three_numbers2(t_stack **a)
{
	t_number	*curr;

	curr = (**a).first;
	if (curr->next->n > curr->next->next->n)
	{
		ft_swap(a);
		ft_reverse_rotate(a);
		ft_putstr("sa\nrra\n");
	}
	else
	{
		if ((**a).first->n < (**a).first->next->next->n)
		{
			ft_swap(a);
			ft_putstr("sa\n");
		}
		else
		{
			ft_rotate(a);
			ft_putstr("ra\n");
		}
	}
}

void	ft_three_numbers(t_stack **a)
{
	t_number	*curr;

	curr = (**a).first;
	if (curr->n > curr->next->n)
		ft_three_numbers2(a);
	else if (curr->n < curr->next->n)
	{
		ft_reverse_rotate(a);
		ft_putstr("rra\n");
		if ((**a).first->n > (**a).first->next->n)
		{
			ft_swap(a);
			ft_putstr("sa\n");
		}
	}
}

int		ft_exit(t_stack *a, t_stack *b)
{
	ft_delete_stacks(a, b);
	return (0);
}

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	if (!(a = malloc(sizeof(*a)))
			|| !(b = malloc(sizeof(*b))))
		return (ft_exit(a, b));
	a->first = NULL;
	b->first = NULL;
	if (ac < 2 || !ft_fill_a(&a, ac, av) || ft_is_sorted(a))
		return (ft_exit(a, b));
	if (ac == 4)
		ft_three_numbers(&a);
	else
		ft_insertion_sort(&a, &b, ac - 1);
	return (ft_exit(a, b));
}
