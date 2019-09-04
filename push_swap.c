/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/04 18:56:32 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sorted(t_stack *a)
{
	t_list	*curr;

	curr = a->head;
	while (curr->next)
	{
		if (*(int *)curr->content > *(int *)curr->next->content)
			break ;
		curr = curr->next;
	}
	if (!curr->next)
		return (1);
	return (0);
}

void	ft_three_numbers2(t_stack **a)
{
	t_list	*curr;

	curr = (**a).head;
	if (*(int *)curr->next->content > *(int *)curr->next->next->content)
	{
		ft_swap(a, 1);
		ft_reverse_rotate(a, 1);
	}
	else
	{
		if (*(int *)(**a).head->content < *(int *)(**a).head->next->next->content)
			ft_swap(a, 1);
		else
			ft_rotate(a, 1);
	}
}

void	ft_three_numbers(t_stack **a)
{
	t_list	*curr;

	curr = (**a).head;
	if (*(int *)curr->content > *(int *)curr->next->content)
		ft_three_numbers2(a);
	else if (*(int *)curr->content < *(int *)curr->next->content)
	{
		ft_reverse_rotate(a, 1);
		if (*(int *)(**a).head->content > *(int *)(**a).head->next->content)
			ft_swap(a, 1);
	}
}

int		ft_exit(t_stack *a, t_stack *b)
{
	ft_delete_stacks(a, b);
	return (0);
}

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	b = NULL;
	if (!(a = malloc(sizeof(a)))
			|| !(b = malloc(sizeof(b))))
		return (ft_exit(a, b));
	a.head = NULL;
	b.head = NULL;
	a.name = 'a';
	b.name = 'b';
	if (ac < 2 || !ft_fill_a(&a, ac, av) || ft_is_sorted(a))
		return (ft_exit(a, b));
	ft_display_stacks(a, b);
	if (ac == 4)
		ft_three_numbers(&a);
	else
		ft_quicksort(a, b);
	return (ft_exit(a, b));
}
