/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:42:25 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/09 14:46:59 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sswap(t_stack *a, t_stack *b, int print_mode)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	if (print_mode)
		ft_putendl("ss");
}

void	ft_rrotate(t_stack *a, t_stack *b, int print_mode)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	if (print_mode)
		ft_putendl("rr");
}

void	ft_rreverse_rotate(t_stack *a, t_stack *b, int print_mode)
{
	ft_reverse_rotate(a, 0);
	ft_reverse_rotate(b, 0);
	if (print_mode)
		ft_putendl("rrr");
}
