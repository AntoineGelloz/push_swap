/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/30 12:57:27 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **s, char c, int print_mode)
{
	t_number	*one;
	t_number	*two;
	int			tmp;

	one = (**s).first;
	tmp = (**s).first->index;
	if (one->next)
	{
		two = one->next;
		(**s).first->index = two->index;
		two->index = tmp;
		one->next = (two->next) ? two->next : NULL;
		two->next = one;
		(**s).first = two;
	}
	if (print_mode)
	{
		ft_putchar('s');
		ft_putchar(c);
		ft_putchar('\n');
	}
}

void	ft_rotate(t_stack **s, char c, int print_mode)
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
	if (print_mode)
	{
		ft_putchar('r');
		ft_putchar(c);
		ft_putchar('\n');
	}
}

void	ft_reverse_rotate(t_stack **s, char c, int print_mode)
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
	if (print_mode)
	{
		ft_putstr("rr");
		ft_putchar(c);
		ft_putchar('\n');
	}
}

void	ft_push(t_stack **s1, t_stack **s2, char c, int print_mode)
{
	t_number	*one;
	t_number	*pushed;
	int			tmp;

	if ((**s1).first)
	{
		tmp = (**s1).first->index;
		one = (**s2).first;
		pushed = (**s1).first;
		(**s2).first = pushed;
		(**s1).first = pushed->next;
		pushed->next = one;
		one = (**s1).first;
		while (one)
		{
			if (one->index > tmp)
				one->index = one->index - 1;
			one = one->next;
		}
		if (pushed->next->index == 0)
			pushed->index = 0;
		else
			pushed->index = pushed->next->index;
		tmp = pushed->index;
		while (pushed->next && pushed->next->index >= tmp)
		{
			pushed->next->index = pushed->next->index + 1;	
			pushed = pushed->next;
		}
	}
	if (print_mode)
	{
		ft_putchar('p');
		ft_putchar(c);
		ft_putchar('\n');
	}
}
