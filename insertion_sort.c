/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/27 16:38:44 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_last(t_stack **s)
{
	t_number	*curr;

	curr = (**s).first;
	while (curr->next)
		curr = curr->next;
	return (curr->n);
}

int		ft_get_size(t_stack **s)
{
	t_number	*curr;
	int			size;

	size = 1;
	curr = (**s).first;
	while (curr->next)
	{
		curr = curr->next;
		size++;
	}
	return (size);

}

void	ft_insertion_sort(t_stack **a, t_stack **b, int elements)
{
	int			sorted;
	int			unsorted;
	int			largest_first;
	int			largest_size;
	t_number	*curr;
	t_number	*beg;
	int			min;
	int			max;

	//Find the largest sorted sequence
	largest_first = 0;
	largest_size = 1;
	curr = (**a).first;
	while (curr->next)
	{
		sorted = 1;
		beg = curr;
		while (curr->next && curr->n < curr->next->n && sorted < elements)
		{
			sorted++;
			curr = curr->next;
		}
		if (sorted > largest_size)
		{
			largest_first = beg->n;
			largest_size = sorted;
		}
		if (curr->next)
			curr = curr->next;
	}

	//Push the unsorted numbers to b from the top of a
	while ((**a).first->n != largest_first)
	{
		if ((**a).first->next->n != largest_first && (**a).first->n < (**a).first->next->n)
			ft_swap(a, 'a', 1);
		ft_push(a, b, 'b', 1);
		if ((**b).first->next && (**b).first->n > (**b).first->next->n)
			ft_swap(b, 'b', 1);
	}
	while ((**b).first && (**b).first->n < (**a).first->n)
	{
		ft_push(b, a, 'a', 1);
		largest_size++;
		largest_first = (**a).first->n;
	}

	//Push the unsorted numbers to b from the bottom of a
	unsorted = ft_get_size(a) - largest_size;
	while (unsorted--)
	{
		if (ft_get_last(a) < (**a).first->n)
		{
			ft_reverse_rotate(a, 'a', 1);
			largest_size++;
			largest_first = (**a).first->n;
		}
		else
		{
			ft_reverse_rotate(a, 'a', 1);
			ft_push(a, b, 'b', 1);
		}
	}

	//Small adjustments to b
	while ((**b).first && (**b).first->next && ((**b).first->n > (**b).first->next->n || (**b).first->n > ft_get_last(b)))
	{
		if ((**b).first->n > (**b).first->next->n)
			ft_swap(b, 'b', 1);
		if ((**b).first->n > ft_get_last(b))
			ft_reverse_rotate(b, 'b', 1);	
	}

	//Insertion of b
	min = (**a).first->n;
	max = ft_get_last(a);
	while ((**b).first)
	{
		if ((**a).first->n < (**b).first->n && (**b).first->n < max)
			ft_rotate(a, 'a', 1);
		else if ((**a).first->n < (**b).first->n && (**b).first->n > max)
		{
			while ((**a).first->n != min)
				ft_rotate(a, 'a', 1);
			ft_push(b, a, 'a', 1);
			max = (**a).first->n;
		}
		else if ((**a).first->n > (**b).first->n && (**b).first->n > ft_get_last(a))
		{
			ft_push(b, a, 'a', 1);
			min = ((**a).first->n < min) ? (**a).first->n : min;
		}
		else if ((**a).first->n > (**b).first->n && (**b).first->n < ft_get_last(a))
			ft_reverse_rotate(a, 'a', 1);
		if ((**b).first && (**b).first->next)
		{
			if ((**b).first->n > (**b).first->next->n)
				ft_swap(b, 'b', 1);
			if ((**b).first->next->n < (**b).first->n && (**b).first->next->n > ft_get_last(a))
			{
				ft_swap(b, 'b', 1);
				ft_push(b, a, 'a', 1);
				min = ((**a).first->n < min) ? (**a).first->n : min;
			}
		}
	}
	while ((**a).first->n > ft_get_last(a))
		ft_rotate(a, 'a', 1);
}
