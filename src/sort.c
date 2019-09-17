/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/14 22:04:05 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_sorted_copy(t_list *list, t_s *s, int elements)
{
	t_list	*sorted_copy;
	t_list	*curr;
	int		index;
	int		i;

	if (!(sorted_copy = ft_lstncpy(list, elements, ft_cpycontent)))
		return (NULL);
	ft_lst_mergesort(&sorted_copy, ft_descending_order);
	curr = sorted_copy;
	index = ft_lstcount(sorted_copy) / 2;
	i = -1;
	while (curr && ++i < index)
		curr = curr->next;
	s->median = *(int *)curr->content;
	return (sorted_copy);
}

int		ft_is_to_push(t_stack *stack, t_s *s, int elements)
{
	if (stack->name == 'a' && *(int *)stack->head->content < s->median)
		return (1);
	else if (stack->name == 'b')
	{
		if ((elements + s->pushed) % 2 > 0
				&& *(int *)stack->head->content > s->median)
			return (1);
		else if ((elements + s->pushed) % 2 == 0
				&& *(int *)stack->head->content >= s->median)
			return (1);
	}
	return (0);
}

int		ft_push_half(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	t_list	*sorted_copy;
	int		limit;
	int		stack_elements;

	stack_elements = stack1->elements;
	sorted_copy = ft_get_sorted_copy(stack1->head, s, elements);
	(stack1->name == 'b') ? ft_lstrev(&sorted_copy) : 0;
	s->pushed = 0;
	s->rotated = 0;
	limit = elements % 2 ? elements / 2 + 1 : elements / 2;
	while (elements > limit)
	{
		if (ft_is_to_push(stack1, s, elements))
		{
			ft_push(stack1, stack2, 1);
			s->pushed++;
			elements--;
		}
		else if (++s->rotated)
			ft_rotate(stack1, 1);
	}
	while (s->pushed + elements != stack_elements && s->rotated--)
		ft_reverse_rotate(stack1, 1);
	ft_lstdel(&sorted_copy, ft_delcontent);
	return (s->pushed);
}

int		ft_unsorted_top(t_stack *stack, t_s *s, int elements)
{
	t_list	*rev;
	t_list	*sorted_copy;
	t_list	*head1;
	t_list	*head2;
	int		i;

	head1 = ft_get_sorted_copy(stack->head, s, stack->elements);
	if (stack->name == 'a')
		ft_lstrev(&head1);
	sorted_copy = ft_lstindex(head1, stack->elements - elements);
	head2 = ft_lstcpy(stack->head, ft_cpycontent);
	rev = ft_lstindex(head2, stack->elements - elements);
	i = -1;
	while (rev != NULL && sorted_copy && ++i < elements)
	{
		if (*(int *)rev->content != *(int *)sorted_copy->content)
			break ;
		sorted_copy = sorted_copy->next;
		rev = rev->next;
	}
	ft_lstdel(&head1, ft_delcontent);
	ft_lstdel(&head2, ft_delcontent);
	return (elements - i);
}

void	ft_sort_sublist(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	uint32_t pushed;

	if (ft_is_sorted(stack1, stack2, elements))
		return ;
	else if ((s->unsorted = ft_unsorted_top(stack1, s, elements)) <= 3)
		ft_sort_top3(stack1, stack2, s, elements);
	else
	{
		pushed = ft_push_half(stack1, stack2, s, elements);
		if (stack1->name == 'a')
		{
			ft_sort_sublist(stack1, stack2, s, elements - pushed);
			ft_sort_sublist(stack2, stack1, s, pushed);
		}
		else
		{
			ft_sort_sublist(stack2, stack1, s, pushed);
			ft_sort_sublist(stack1, stack2, s, elements - pushed);
		}
	}
}
