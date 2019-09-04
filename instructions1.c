/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:42:25 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/04 18:42:27 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *src, t_stack *dest, int print_mode)
{
	ft_lstpush(&src->head, &dest->head);
	src->len--;
	dest->len++;
	if (verbose)
		ft_printf("p%c\n", ft_tolower(dest->stack_name));
}

void	ft_swap(t_stack *current, int print_mode)
{
	if (ft_lstcount(current->head) >= 2)
		current->head = ft_lstswap(current->head, current->head->next);
	if (verbose)
		ft_printf("s%c\n", ft_tolower(STACK));
}

void	ft_sswap(t_stack *a, t_stack *b, int print_mode)
{
	swap(a, 0);
	swap(b, 0);
	if (verbose)
		ft_putendl("ss");
}
