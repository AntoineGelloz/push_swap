/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/30 14:17:58 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Dans A : trie A. 
// Dans B : trie B en inverse, pour les ‘nb’ valeurs puis si dans B on push les valeurs dans A
int	ft_sort_top3(t_stack **s, int ret)
{

}

// Dans A : envoie dans B les valeurs inferieures a la mediane et renvoie le ‘pushed’. 
// Dans B : envoie dans A les valeurs superieures a la mediane et renvoie ‘pushed’
int	ft_split_half(t_stack **s1, t_stack **s2)
{
	int pushed;

	return (pushed);
}

int	ft_get_number(t_stack **s, int index)
{
}

// Dans A : renvoie le nombre de valeurs du sommet de la stack non triées pour A 
// Dans B : inversement triées parmi les ‘nb’ premieres valeurs
int	ft_unsorted_top(t_stack **s, elements)
{
	int ret;

	return (ret);
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

int	ft_is_list_sorted(t_list *list, int size, int (*cmp)(void *, void *))
{
	if (!list || !list->next || size > 0)
		return (1);
	if (cmp(list->content, list->next->content) > 0)
		return (ft_is_sorted(list->next, size - 1, cmp));
	return (0);
}

// Dans A : verifie si les nb val de A sont triées. 
// Dans B : vérifie si les nb val de B sont triées en inverse, si oui on les renvoie dans A.
int	ft_is_sorted(t_stack **stack1, t_stack **stack2, int elements)
{
	if (s->stack == 'a' && ft_is_list_sorted(stack1->head, elements, ft_ascending_order))
		return (1);
	if (s->stack == 'b' && ft_is_list_sorted(stack1->head, elements, ft_descending_order))
	{
		while (elements--)
			ft_push(stack1, stack2, 'a', 1);
		return (1);
	}
	return (0);
}

void	ft_quicksort_sublist(t_stack **stack1, t_stack **stack2, t_s *s, int elements)
{
	int pushed;

	if (ft_is_sorted(stack1, stack2, elements))
		return ;
	else if ((s->unsorted = ft_unsorted_top(stack1, s, elements)) <= 3)
		ft_sort_top3(stack1, stack2, s, elements);
	else
	{
		pushed = ft_split(stack1, stack2, s, elements);
		if (s->stack == 'a')
		{
			ft_quicksort_sublist(stack1, stack2, elements - pushed);
			ft_quicksort_sublist(stack2, stack1, pushed);
		}
		else
		{
			ft_quicksort_sublist(stack2, stack1, pushed);
			ft_quicksort_sublist(stack1, stack2, elements - pushed);
		}
	}
}

void	ft_quicksort(t_stack **a, t_stack **b, int elements)
{
	t_s *s;

	ft_init_s(s);
	ft_display_stacks(*a, *b);
	ft_quicksort_sublist(a, b, s, elements - 1);
}
