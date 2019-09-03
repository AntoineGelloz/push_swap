/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/03 16:44:58 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **s, char c, int print_mode)
{
	t_list	*one;
	t_list	*two;

	one = (**s).head;
	if (one->next)
	{
		two = one->next;
		one->next = (two->next) ? two->next : NULL;
		two->next = one;
		(**s).head = two;
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
	t_list	*one;
	t_list	*curr;

	one = (**s).head;
	curr = (**s).head;
	while (curr->next)
		curr = curr->next;
	((**s).head->next) ? (**s).head = (**s).head->next : 0;
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
	t_list	*one;
	t_list	*curr;

	one = (**s).head;
	curr = (**s).head;
	while (curr->next->next)
		curr = curr->next;
	(**s).head = curr->next;
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
	t_list	*one;
	t_list	*pushed;

	if ((**s1).head)
	{
		one = (**s2).head;
		pushed = (**s1).head;
		(**s2).head = pushed;
		(**s1).head = pushed->next;
		pushed->next = one;
		one = (**s1).head;
	}
	if (print_mode)
	{
		ft_putchar('p');
		ft_putchar(c);
		ft_putchar('\n');
	}
}
