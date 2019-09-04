/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/04 18:27:53 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_list_max(t_list *list, int size)
{
	int		max;

	max = *(int *)list->content;
	while (list && size--)
	{
		if (*(int *)list->content > max)
			max = *(int *)list->content;
		list = list->next;
	}
	return (max);
}

int		ft_get_list_min(t_list *list, int size)
{
	int		min;

	min = *(int *)list->content;
	while (list && size--)
	{
		if (*(int *)list->content < min)
			min = *(int *)list->content;
		list = list->next;
	}
	return (min);
}

void	ft_update_s(t_stack *stack, t_s *s, int elements)
{
	s->max = ft_get_list_max(stack->head, s->unsorted);
	s->min = ft_get_list_min(stack->head, s->unsorted);
	s->nb1 = *(int *)stack->head->content;
	s->nb2 = *(int *)stack->head->next->content;
	if (elements >= 3)
		s->nb3 = *(int *)stack->head->next->next->content;	
}

void	ft_delcontent(void *content, size_t size)
{
	if (content && size)
		free(content);
}

int	ft_ascending_order(void *a, void *b)
{
	int elem1;
	int elem2;

	elem1 = *(int *)a;
	elem2 = *(int *)b;
	return (elem1 <= elem2);
}

int	ft_descending_order(void *a, void *b)
{
	int elem1;
	int elem2;

	elem1 = *(int *)a;
	elem2 = *(int *)b;
	return (elem1 >= elem2);
}

int	ft_copy_values(void *dst, void *src)
{
	*(int *)dst = *(int *)src;
	return (0);
}

int	ft_get_median_value(t_list *list)
{
	int     k;
	int     index;

	index = ft_lstcount(list) / 2;
	k = -1;
	while (list && ++k < index)
		list = list->next;
	return (*(int *)list->content);
}

t_list	*ft_get_sorted_copy(t_list *list, t_s *s, int elements)
{
	t_list  *sorted_copy;

	ft_putstr("get-sorted_copy\n");
	if (!(sorted_copy = ft_lstncpy(list, elements, ft_copy_values)))
		return (NULL);
	ft_putstr("sorted_copy\n");
	ft_lst_mergesort(&sorted_copy, ft_descending_order);
	s->median = ft_get_median_value(sorted_copy);
	return (sorted_copy);
}

t_list	*ft_init_split(t_stack *stack, int *size, t_s *s, int elements)
{
	t_list	*new_list;

	*size = stack->elements;
	new_list = ft_get_sorted_copy(stack->head, s, elements);
	if (stack->name == 'b')
		ft_lstrev(&new_list);
	s->pushed = 0;
	s->rotated = 0;
	return (new_list);
}

int	ft_is_to_push(t_stack *stack, t_s *s, int elements)
{
	if (stack->name == 'a' && *(int *)stack->head->content < s->median)
		return (1);
	else if (stack->name == 'b')
	{
		if ((elements + s->pushed) % 2 > 0 && *(int *)stack->head->content > s->median)
			return (1);
		else if ((elements + s->pushed) == 0 && *(int *)stack->head->content >= s->median)
			return (1);
	}
	return (0);
}

// Dans A : envoie dans B les valeurs inferieures a la mediane et renvoie le ‘pushed’. 
// Dans B : envoie dans A les valeurs superieures a la mediane et renvoie ‘pushed’
int	ft_split_half(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	t_list	*sorted_copy;
	int		limit;
	int		stack_len;

	sorted_copy = ft_init_split(stack1, &stack_len, s, elements);
	limit = elements % 2 ? elements / 2 + 1 : elements / 2;
	while (elements > limit)
	{
		sleep(1);
		if (ft_is_to_push(stack1, s, elements))
		{
			if (stack1->name == 'a')
				ft_push(&stack1, &stack2, 'a', 1);
			else
				ft_push(&stack1, &stack2, 'b', 1);
			s->pushed++;
			elements--;
		}
		else if (++s->rotated)
		{
			if (stack1->name == 'a')
				ft_rotate(&stack1, 'a', 1);
			else
				ft_rotate(&stack1, 'b', 1);
		}
	}
	if (s->pushed + elements != stack_len)
	{
		while (s->rotated--)
		{
			if (stack1->name == 'a')
				ft_reverse_rotate(&stack1, 'a', 1);
			else
				ft_reverse_rotate(&stack1, 'b', 1);
		}
	}
	ft_lstdel(&sorted_copy, ft_delcontent);
	return (s->pushed);
}

void	ft_sort_b(t_stack *a, t_stack *b, t_s *s)
{
	if (s->nb1 == s->max)
	{
		ft_push(&b, &a, 'a', 1);
		ft_swap(&b, 'b', 1);
		ft_push(&b, &a, 'a', 1);
		ft_push(&b, &a, 'a', 1);
	}
	else if (s->nb1 == s->min)
	{
		ft_swap(&b, 'b', 1);
		ft_push(&b, &a, 'a', 1);
		ft_swap(&b, 'b', 1);
		ft_push(&b, &a, 'a', 1);
		if (s->nb2 != s->max)
			ft_swap(&a, 'a', 1);
		ft_push(&b, &a, 'a', 1);
	}
	else
	{
		if (s->nb2 == s->min)
		{
			ft_push(&b, &a, 'a', 1);
			ft_swap(&b, 'b', 1);
			ft_push(&b, &a, 'a', 1);
			ft_swap(&a, 'a', 1);
			ft_push(&b, &a, 'a', 1);
		}
		else
		{
			ft_swap(&b, 'b', 1);
			ft_push(&b, &a, 'a', 1);
			ft_push(&b, &a, 'a', 1);
			ft_push(&b, &a, 'a', 1);
		}
	}
}

void	ft_sort_a(t_stack *a, t_stack *b, t_s *s)
{
	if (s->nb1 == s->max)
	{
		ft_swap(&a, 'a', 1);
		ft_push(&a, &b, 'b', 1);
		ft_swap(&a, 'a', 1);
		ft_push(&b, &a, 'a', 1);
	}
	if (s->nb2 != s->min)
		ft_swap(&a, 'a', 1);
	else if (s->nb1 == s->min)
	{
		ft_push(&a, &b, 'b', 1);
		ft_swap(&a, 'a', 1);
		ft_push(&b, &a, 'a', 1);
	}
	else
	{
		if (s->nb2 == s->min)
			ft_swap(&a, 'a', 1);
		else
		{
			ft_push(&a, &b, 'b', 1);
			ft_swap(&a, 'a', 1);
			ft_push(&b, &a, 'a', 1);
			ft_swap(&a, 'a', 1);
		}
	}
}

void	ft_simple_sort_a(t_stack *a, t_s *s)
{
	if (s->nb1 == s->max)
	{
		if (s->nb2 == s->min)
			ft_rotate(&a, 'a', 1);
		else
		{
			ft_swap(&a, 'a', 1);
			ft_reverse_rotate(&a, 'a', 1);
		}
	}
	else if (s->nb1 != s->min && s->nb1 != s->max)
		s->nb2 == s->min ? ft_swap(&a, 'a', 1) : ft_reverse_rotate(&a, 'a', 1);
	else
	{
		ft_reverse_rotate(&a, 'a', 1);
		ft_swap(&a, 'a', 1);
	}
}

void	ft_simple_sort_b(t_stack *b, t_s *s)
{
	if (s->nb1 == s->max)
	{
		ft_reverse_rotate(&b, 'b', 1);
		ft_swap(&b, 'b', 1);
	}
	else if (s->nb1 == s->min)
	{
		if (s->nb2 == s->max)
			ft_rotate(&b, 'b', 1);
		else
		{
			ft_rotate(&b, 'b', 1);
			ft_swap(&b, 'b', 1);
		}
	}
	else
	{
		if (s->nb2 == s->max)
			ft_swap(&b, 'b', 1);
		else
			ft_reverse_rotate(&b, 'b', 1);
	}
}

void	ft_sort_top2(t_stack *stack1, t_stack *stack2, int elements)
{
	if (stack1->name == 'a')
		ft_swap(&stack1, 'a', 1);
	else
	{
		ft_swap(&stack1, 'b', 1);
		while (elements--)
			ft_push(&stack1, &stack2, 'b', 1);
	}
}

// Dans A : trie A. 
// Dans B : trie B en inverse, pour les ‘nb’ valeurs puis si dans B on push les valeurs dans A
void	ft_sort_top3(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	ft_update_s(stack1, s, elements);
	if (s->unsorted == 2)
		ft_sort_top2(stack1, stack2, elements);
	else if (elements == stack1->elements && stack1->elements <= 3)
	{
		if (stack1->name == 'a')
			ft_simple_sort_a(stack1, s);
		else
		{
			ft_simple_sort_b(stack1, s);
			while (elements--)
				ft_push(&stack1, &stack2, 'b', 1);
		}
	}
	else
	{
		if (stack1->name == 'a')
			ft_sort_a(stack1, stack2, s);
		else
		{
			ft_sort_b(stack2, stack1, s);
			printf("elements:%d\n", elements);
			while (elements-- - 3)
			{
				sleep(1);
				ft_push(&stack1, &stack2, 'b', 1);
			}
		}
	}
}

t_list	*ft_lstindex(t_list *list, int index)
{
	while (list && index--)
		list = list->next;
	return (list);
}

// Dans A : renvoie le nombre de valeurs du sommet de la stack non triées pour A 
// Dans B : inversement triées parmi les ‘nb’ premieres valeurs
int	ft_unsorted_top(t_stack *stack, t_s *s, int elements)
{
	t_list  *rev;
	t_list  *sorted_copy;
	t_list  *head1;
	t_list  *head2;
	int		i;

	ft_putstr("unsorted_top\n");
	head1 = ft_get_sorted_copy(stack->head, s, stack->elements);
	ft_putstr("done\n");
	if (stack->name == 'a')
		ft_lstrev(&head1);
	ft_putstr("done2\n");
	sorted_copy = ft_lstindex(head1, stack->elements - elements);
	ft_putstr("done3\n");
	head2 = ft_lstcpy(stack->head, ft_copy_values);
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
	return (elements - i);
}


int	ft_is_list_sorted(t_list *list, int elements, int (*ft_order)(void *, void *))
{
	if (!list || !list->next || elements == 0)
		return (1);
	printf("is_list_sorted elem:%d\n", elements);
	if (ft_order(list->content, list->next->content) > 0)
		return (ft_is_list_sorted(list->next, elements - 1, ft_order));
	return (0);
}

// Dans A : verifie si les nb val de A sont triées. 
// Dans B : vérifie si les nb val de B sont triées en inverse, si oui on les renvoie dans A.
int	ft_is_partially_sorted(t_stack *stack1, t_stack *stack2, int elements)
{
	printf("stack1:%c-stack2:%c\n", stack1->name, stack2->name);
	if (stack1->name == 'a' && ft_is_list_sorted(stack1->head, elements, ft_ascending_order))
		return (1);
	if (stack1->name == 'b' && ft_is_list_sorted(stack1->head, elements, ft_descending_order))
	{
		printf("Push tout de b vers a\n");
		while (elements--)
			ft_push(&stack1, &stack2, 'a', 1);
		return (1);
	}
	ft_putendl("not sorted");
	return (0);
}

void	ft_quicksort_sublist(t_stack *stack1, t_stack *stack2, t_s *s, int elements)
{
	int pushed;

	ft_putchar('\n');
	ft_display_stacks(stack1, stack2);
	printf("elements:%d\n", elements);
	if (ft_is_partially_sorted(stack1, stack2, elements))
	{
		ft_putstr("case1\n");
		return ;
	}
	else if ((s->unsorted = ft_unsorted_top(stack1, s, elements)) <= 3)
	{
		ft_putstr("case2\n");
		ft_sort_top3(stack1, stack2, s, elements);
	}
	else
	{
		ft_putstr("case3\n");
		pushed = ft_split_half(stack1, stack2, s, elements);
		if (stack1->name == 'a')
		{
			sleep(1);
			ft_quicksort_sublist(stack1, stack2, s, elements - pushed);
			ft_quicksort_sublist(stack2, stack1, s, pushed);
		}
		else
		{
			sleep(1);
			ft_quicksort_sublist(stack2, stack1, s, pushed);
			ft_quicksort_sublist(stack1, stack2, s, elements - pushed);
		}
	}
}

void	ft_quicksort(t_stack *a, t_stack *b)
{
	t_s s;

	s.median = 0;
	s.max = 0;
	s.min = 0;
	s.nb1 = 0;
	s.nb2 = 0;
	s.nb3 = 0;
	s.pushed = 0;
	s.rotated = 0;
	s.initial_elements = a->elements;
	ft_quicksort_sublist(a, b, &s, s.initial_elements);
}
