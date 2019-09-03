/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/03 16:51:32 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_stacks(t_stack *a, t_stack *b)
{
	t_list	*curr;

	curr = a->head;
	ft_putstr("a");
	ft_putchar('|');
	while (curr)
	{
		if (curr != a->head)
			ft_putchar(' ');
		ft_putnbr(curr->content_size);
		curr = curr->next;
	}
	ft_putchar('|');
	curr = (b->head) ? b->head : NULL;
	ft_putstr(" b");
	ft_putchar('|');
	while (curr)
	{
		if (curr != b->head)
			ft_putchar(' ');
		ft_putnbr(curr->content_size);
		curr = curr->next;
	}
	ft_putchar('|');
}
