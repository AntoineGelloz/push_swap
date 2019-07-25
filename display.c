/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/25 18:06:36 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_stacks(t_stack *a, t_stack *b)
{
	t_number	*curr;

	curr = a->first;
	ft_putstr("a");
	ft_putchar('|');
	while (curr)
	{
		if (curr != a->first)
			ft_putchar(' ');
		ft_putnbr(curr->n);
		curr = curr->next;
	}
	ft_putchar('|');
	curr = (b->first) ? b->first : NULL;
	ft_putstr(" b");
	ft_putchar('|');
	while (curr)
	{
		if (curr != b->first)
			ft_putchar(' ');
		ft_putnbr(curr->n);
		curr = curr->next;
	}
	ft_putchar('|');
}
