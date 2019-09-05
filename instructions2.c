/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:42:35 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/05 11:50:46 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf.h"

void	ft_rotate(t_stack *s, int print_mode)
{
	if (ft_lstcount(s->head) >= 2)
		ft_lstrotate(&s->head);
	if (print_mode)
		ft_printf("r%c\n", s->name);
}

void	ft_rrotate(t_stack *a, t_stack *b, int print_mode)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	if (print_mode)
		ft_putendl("rr");
}

void	ft_reverse_rotate(t_stack *s, int print_mode)
{
	if (ft_lstcount(s->head) >= 2)
		ft_lstrevrotate(&s->head);
	if (print_mode)
		ft_printf("rr%c\n", s->name);
}

void	ft_rreverse_rotate(t_stack *a, t_stack *b, int print_mode)
{
	ft_reverse_rotate(a, 0);
	ft_reverse_rotate(b, 0);
	if (print_mode)
		ft_putendl("rrr");
}
