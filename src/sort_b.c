/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/10 11:52:39 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b_2(t_stack *a, t_stack *b, t_s *s)
{
	if (s->nb2 == s->min)
	{
		ft_push(b, a, 1);
		ft_swap(b, 1);
		ft_push(b, a, 1);
		ft_swap(a, 1);
		ft_push(b, a, 1);
	}
	else
	{
		ft_swap(b, 1);
		ft_push(b, a, 1);
		ft_push(b, a, 1);
		ft_push(b, a, 1);
	}
}

void	ft_sort_b(t_stack *a, t_stack *b, t_s *s)
{
	if (s->nb1 == s->max)
	{
		ft_push(b, a, 1);
		ft_swap(b, 1);
		ft_push(b, a, 1);
		ft_push(b, a, 1);
	}
	else if (s->nb1 == s->min)
	{
		ft_swap(b, 1);
		ft_push(b, a, 1);
		ft_swap(b, 1);
		ft_push(b, a, 1);
		if (s->nb2 != s->max)
			ft_swap(a, 1);
		ft_push(b, a, 1);
	}
	else
		ft_sort_b_2(a, b, s);
}

void	ft_sort_only3_b(t_stack *b, t_s *s)
{
	if (s->nb1 == s->max)
	{
		ft_reverse_rotate(b, 1);
		ft_swap(b, 1);
	}
	else if (s->nb1 == s->min)
	{
		if (s->nb2 == s->max)
			ft_rotate(b, 1);
		else
		{
			ft_rotate(b, 1);
			ft_swap(b, 1);
		}
	}
	else
	{
		if (s->nb2 == s->max)
			ft_swap(b, 1);
		else
			ft_reverse_rotate(b, 1);
	}
}
