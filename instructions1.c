/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:42:25 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/05 11:50:33 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf.h"

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

void	ft_sswap(t_stack *a, t_stack *b, int print_mode)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	if (print_mode)
		ft_putendl("ss");
}
