/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:22:09 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/10 12:23:29 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_s(t_stack *stack, t_s *s, int elements)
{
	s->max = ft_lstgetmax(stack->head, s->unsorted);
	s->min = ft_lstgetmin(stack->head, s->unsorted);
	s->nb1 = *(int *)stack->head->content;
	s->nb2 = *(int *)stack->head->next->content;
	if (elements >= 3)
		s->nb3 = *(int *)stack->head->next->next->content;
}

void	ft_sort_top3_2(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	if (stack1->name == 'a')
		ft_sort_a(stack1, stack2, s);
	else
	{
		ft_sort_b(stack2, stack1, s);
		while (elements-- - 3)
			ft_push(stack1, stack2, 1);
	}
}

void	ft_sort_top3(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	ft_update_s(stack1, s, elements);
	if (s->unsorted == 2)
	{
		ft_swap(stack1, 1);
		while (stack1->name == 'b' && elements--)
			ft_push(stack1, stack2, 1);
	}
	else if (elements == stack1->elements && stack1->elements <= 3)
	{
		if (stack1->name == 'a')
			ft_sort_only3_a(stack1, s);
		else
		{
			ft_sort_only3_b(stack1, s);
			while (elements--)
				ft_push(stack1, stack2, 1);
		}
	}
	else
		ft_sort_top3_2(stack1, stack2, s, elements);
}

int		ft_is_sorted(t_stack *stack1, t_stack *stack2, int elements)
{
	if (stack1->name == 'a'
			&& ft_lstsorted(stack1->head, elements, ft_ascending_order))
		return (1);
	if (stack1->name == 'b'
			&& ft_lstsorted(stack1->head, elements, ft_descending_order))
	{
		while (elements--)
			ft_push(stack1, stack2, 1);
		return (1);
	}
	return (0);
}
