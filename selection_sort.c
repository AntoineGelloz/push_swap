/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/27 17:30:56 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** While stack a is not empty
**		Find the smallest number and its position
** 		Rotate stack a until the smallest is on top and push it on b
** Push everything back to a
*/

#include "push_swap.h"

void	ft_selection_sort(t_stack **a, t_stack **b, int elements)
{
	t_number	*curr;
	t_number	*smallest;
	int			i;
	int			pos;

	while ((**a).first->next)
	{
		curr = (**a).first;
		smallest = curr;
		i = 0;
		pos = 0;
		while (curr)
		{
			if (curr->n < smallest->n)
			{
				pos = i;
				smallest = curr;
			}
			i++;
			curr = curr->next;
		}
		curr = (**a).first;
		while ((**a).first != smallest)
		{
			if (pos < elements / 2)
				ft_rotate(a, 'a', 1);
			else
				ft_reverse_rotate(a, 'a', 1);
		}
		ft_push(a, b, 'b', 1);
	}
	while ((**b).first)
		ft_push(b, a, 'a', 1);
}
