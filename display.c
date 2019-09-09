/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:16:03 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/09 17:16:00 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_stacks(t_stack *stack1, t_stack *stack2)
{
	t_list	*curr;

	curr = stack1->head;
	ft_printf("%c|", stack1->name);
	while (curr)
	{
		if (curr != stack1->head)
			ft_putchar(' ');
		ft_putnbr(*(int *)curr->content);
		curr = curr->next;
	}
	curr = (stack2->head) ? stack2->head : NULL;
	ft_printf("| %c|", stack2->name);
	while (curr)
	{
		if (curr != stack2->head)
			ft_putchar(' ');
		ft_putnbr(*(int *)curr->content);
		curr = curr->next;
	}
	ft_putendl("|");
}
