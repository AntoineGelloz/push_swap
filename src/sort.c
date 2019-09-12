/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/12 15:49:14 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_s(t_stack *stack, t_s *s, int elements)
{
	//ft_printf("update s\n");
	s->max = ft_lstgetmax(stack->head, s->unsorted);
	s->min = ft_lstgetmin(stack->head, s->unsorted);
	s->nb1 = *(int *)stack->head->content;
	s->nb2 = *(int *)stack->head->next->content;
	if (elements >= 3)
		s->nb3 = *(int *)stack->head->next->next->content;
}

t_list	*ft_get_sorted_copy(t_list *list, t_s *s, int elements)
{
	t_list  *sorted_copy;
	t_list  *curr;
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
	//printf("median:%d\n", s->median);
	return (sorted_copy);
}

int		ft_is_to_push(t_stack *stack, t_s *s, int elements)
{
	if (stack->name == 'a' && *(int *)stack->head->content < s->median)
		return (1);
	else if (stack->name == 'b')
	{
		if ((elements + s->pushed) % 2 > 0 && *(int *)stack->head->content > s->median)
			return (1);
		else if ((elements + s->pushed) % 2 == 0 && *(int *)stack->head->content >= s->median)
			return (1);
	}
	return (0);
}

// Dans A : envoie dans B les valeurs inferieures a la mediane et renvoie le ‘pushed’ 
// Dans B : envoie dans A les valeurs superieures a la mediane et renvoie le ‘pushed’
int		ft_push_half(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	t_list	*sorted_copy;
	int		limit;
	int		stack_elements;

	//ft_printf("push_half:%d %c->%c\n", stack1->elements, stack1->name, stack2->name);
	stack_elements = stack1->elements;
	sorted_copy = ft_get_sorted_copy(stack1->head, s, elements);
	if (stack1->name == 'b')
		ft_lstrev(&sorted_copy);
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
	if (s->pushed + elements != stack_elements)
		while (s->rotated--)
			ft_reverse_rotate(stack1, 1);
	ft_lstdel(&sorted_copy, ft_delcontent);
	return (s->pushed);
}

// Dans A : trie A 
// Dans B : trie B en inverse, pour les ‘nb’ valeurs puis si dans B on push les valeurs dans A
void	ft_sort_top3(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	//ft_printf("sort_top3:%d elements\n", elements);
	ft_update_s(stack1, s, elements);
	if (s->unsorted == 2)
	{
		ft_swap(stack1, 1);
		if (stack1->name == 'b')
			while (elements--)
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
}

// Dans A : renvoie le nombre de valeurs du sommet de la stack non triées pour A 
// Dans B : inversement triées parmi les ‘nb’ premieres valeurs
int		ft_unsorted_top(t_stack *stack, t_s *s, int elements)
{
	t_list  *rev;
	t_list  *sorted_copy;
	t_list  *head1;
	t_list  *head2;
	int		i;

	head1 = ft_get_sorted_copy(stack->head, s, stack->elements);
	if (stack->name == 'a')
		ft_lstrev(&head1);
	sorted_copy = ft_lstindex(head1, stack->elements - elements);
	head2 = ft_lstcpy(stack->head, ft_cpycontent);
	rev = ft_lstindex(head2, stack->elements - elements);
	i = -1;
	while (rev && sorted_copy && ++i < elements)
	{
		if (*(int *)rev->content != *(int *)sorted_copy->content)
			break ;
		sorted_copy = sorted_copy->next;
		rev = rev->next;
	}
	ft_lstdel(&head1, ft_delcontent);
	ft_lstdel(&head2, ft_delcontent);
	//ft_printf("unsorted top:%d stack:%c\n", elements - i, stack->name);
	return (elements - i);
}

// Dans A : verifie si les nb val de A sont triées. 
// Dans B : vérifie si les nb val de B sont triées en inverse, si oui on les renvoie dans A.
int		ft_is_sorted(t_stack *stack1, t_stack *stack2, int elements)
{
	if (stack1->name == 'a' && ft_lstsorted(stack1->head, elements, ft_ascending_order))
	{
		//printf("a sorted\n");
		return (1);
	}
	if (stack1->name == 'b' && ft_lstsorted(stack1->head, elements, ft_descending_order))
	{
		//printf("b sorted: Push tout de b vers a\n");
		while (elements--)
			ft_push(stack1, stack2, 1);
		return (1);
	}
	return (0);
}

void	ft_sort_sublist(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	int pushed;

	//ft_display_stacks(stack1, stack2);
	//printf("elements:%d\n", elements);
	if (ft_is_sorted(stack1, stack2, elements))
	{
		//ft_putstr("--All sorted\n");
		return ;
	}
	else if ((s->unsorted = ft_unsorted_top(stack1, s, elements)) <= 3)
	{
		//ft_putstr("--3 elements unsorted on stack1 or less\n");
		//ft_printf("--%d elements unsorted on stack %c\n", s->unsorted, stack1->name);
		ft_sort_top3(stack1, stack2, s, elements);
	}
	else
	{
		//ft_putstr("--Else\n");
		pushed = ft_push_half(stack1, stack2, s, elements);
		//ft_printf("pushed:%d\n", pushed);
		if (stack1->name == 'a')
		{
			//ft_putendl("1");
			ft_sort_sublist(stack1, stack2, s, elements - pushed);
			//ft_putendl("2");
			ft_sort_sublist(stack2, stack1, s, pushed);
		}
		else
		{
			//ft_putendl("3");
			ft_sort_sublist(stack2, stack1, s, pushed);
			//ft_putendl("4");
			ft_sort_sublist(stack1, stack2, s, elements - pushed);
		}
	}
}
