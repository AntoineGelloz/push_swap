/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/05 18:02:45 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isstack_sorted(t_stack *a)
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

int		ft_exit(t_stack *a, t_stack *b)
{
	a = NULL;
	b = NULL;
	//ft_delete_stacks(a, b);
	return (0);
}

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	a.head = NULL;
	b.head = NULL;
	a.name = 'a';
	b.name = 'b';
	a.elements = 0;
	b.elements = 0;
	if (ac < 2 || !ft_fill_a(&a, ac, av) || ft_isstack_sorted(&a))
		return (ft_exit(&a, &b));
	//ft_display_stacks(&a, &b);
	ft_quicksort(&a, &b);
	//ft_display_stacks(&a, &b);
	return (ft_exit(&a, &b));
}
