/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/09 17:12:09 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_stack_sorted(t_stack *a)
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

void	ft_init_s(t_s *s)
{
	s->median = 0;
	s->max = 0;
	s->min = 0;
	s->nb1 = 0;
	s->nb2 = 0;
	s->nb3 = 0;
	s->pushed = 0;
	s->rotated = 0;
}

int		main(int ac, char **av)
{
	t_s		s;
	t_stack	a;
	t_stack	b;

	a.head = NULL;
	b.head = NULL;
	a.name = 'a';
	b.name = 'b';
	a.elements = 0;
	b.elements = 0;
	if (ac < 2)
		return (0);
	if (!ft_fill_a(&a, ac, av, 0))
		return (ft_error_exit(&a));
	if (ft_is_stack_sorted(&a))
		return (0);
	ft_init_s(&s);
	s.initial_elements = a.elements;
	ft_sort_sublist(&a, &b, &s, a.elements);
	ft_delete_stacks(&a, &b);
	return (0);
}
