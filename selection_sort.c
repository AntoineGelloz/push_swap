/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/26 19:30:15 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** While stack a is not empty
**		Find the smallest number and its position
** 		Rotate stack a until the smallest is on top and push it on b
** Push everything back to a
*/

#include "push_swap.h"

void	ft_selection_sort(t_stack **a, t_stack **b, int n)
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
			if (pos < n / 2)
			{
				ft_putstr("ra\n");
				ft_rotate(a);
			}
			else
			{	
				ft_putstr("rra\n");
				ft_reverse_rotate(a);
			}
		}
		ft_putstr("pb\n");
		ft_push(a, b);
	}
	while ((**b).first)
	{
		ft_putstr("pa\n");
		ft_push(b, a);
	}
}
