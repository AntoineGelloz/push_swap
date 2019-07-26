/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/26 19:29:38 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **s)
{
	t_number	*one;
	t_number	*two;

	one = (**s).first;
	if (one->next)
	{
		two = one->next;
		one->next = (two->next) ? two->next : NULL;
		two->next = one;
		(**s).first = two;
	}
}

void	ft_rotate(t_stack **s)
{
	t_number	*one;
	t_number	*curr;

	one = (**s).first;
	curr = (**s).first;
	while (curr->next)
		curr = curr->next;
	((**s).first->next) ? (**s).first = (**s).first->next : 0;
	curr->next = one;	
	curr->next->next = NULL;
}

void	ft_reverse_rotate(t_stack **s)
{
	t_number	*one;
	t_number	*curr;

	one = (**s).first;
	curr = (**s).first;
	while (curr->next->next)
		curr = curr->next;
	(**s).first = curr->next;
	curr->next->next = one;
	curr->next = NULL;
}

void	ft_push(t_stack **s1, t_stack **s2)
{
	t_number	*one;
	t_number	*pushed;

	if ((**s1).first)
	{
		one = (**s2).first;
		pushed = (**s1).first;
		(**s2).first = pushed;
		(**s1).first = pushed->next;
		pushed->next = one;
	}
}
