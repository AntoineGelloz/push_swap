/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:42:25 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/09 14:19:33 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *src, t_stack *dst, int print_mode)
{
	ft_lstpush(&src->head, &dst->head);
	src->elements--;
	dst->elements++;
	if (print_mode)
		ft_printf("p%c\n", dst->name);
}

void	ft_swap(t_stack *s, int print_mode)
{
	if (ft_lstcount(s->head) >= 2)
		s->head = ft_lstswap(s->head, s->head->next);
	if (print_mode)
		ft_printf("s%c\n", s->name);
}

void	ft_rotate(t_stack *s, int print_mode)
{
	if (ft_lstcount(s->head) >= 2)
		ft_lstrotate(&s->head);
	if (print_mode)
		ft_printf("r%c\n", s->name);
}

void	ft_reverse_rotate(t_stack *s, int print_mode)
{
	if (ft_lstcount(s->head) >= 2)
		ft_lstrevrotate(&s->head);
	if (print_mode)
		ft_printf("rr%c\n", s->name);
}
