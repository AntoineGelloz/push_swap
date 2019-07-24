/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/24 17:37:21 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_selection_sort(t_stack **a, t_stack **b, int n)
{
	t_number	*curr;
	t_number	*smallest;
	int			i;
	int			pos;

	//While stack a isn't empty
	while ((**a).first->next)
	{
		//Find the smallest number and its position
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
		//Rotate or reverse rotate stack a until the smallest is on top and push it on b
		curr = (**a).first;
		while ((**a).first != smallest)
		{
			if (pos < n / 2)
			{
				ft_putstr("ra");
				*a = ft_rotate(a);
			}
			else
			{	
				ft_putstr("rra");
				*a = ft_reverse_rotate(a);
			}
			//ft_display_stacks(*a, *b);
			ft_putchar('\n');
		}
		ft_putstr("pb");
		*b = ft_push(b, a);
		//ft_display_stacks(*a, *b);
		ft_putchar('\n');
	}
	//Push back everything on a
	while ((**b).first)
	{
		ft_putstr("pa");
		*a = ft_push(a, b);
		//ft_display_stacks(*a, *b);
		ft_putchar('\n');
	}
}
