/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/09 14:24:47 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a_2(t_stack *a, t_stack *b, t_s *s)
{
	if (s->nb2 == s->min)
		ft_swap(a, 1);
	else
	{
		ft_push(a, b, 1);
		ft_swap(a, 1);
		ft_push(b, a, 1);
		ft_swap(a, 1);
	}
}

void	ft_sort_a(t_stack *a, t_stack *b, t_s *s)
{
	//ft_putstr("sort a\n");
	if (s->nb1 == s->max)
	{
		ft_swap(a, 1);
		ft_push(a, b, 1);
		ft_swap(a, 1);
		ft_push(b, a, 1);
		if (s->nb2 != s->min)
			ft_swap(a, 1);
	}
	else if (s->nb1 == s->min)
	{
		ft_push(a, b, 1);
		ft_swap(a, 1);
		ft_push(b, a, 1);
	}
	else
		ft_sort_a_2(a, b, s);	
}

void	ft_sort_only3_a(t_stack *a, t_s *s)
{
	//ft_putstr("sort_only3_a\n");
	if (s->nb1 == s->max)
	{
		if (s->nb2 == s->min)
			ft_rotate(a, 1);
		else
		{
			ft_swap(a, 1);
			ft_reverse_rotate(a, 1);
		}
	}
	else if (s->nb1 != s->min && s->nb1 != s->max)
		s->nb2 == s->min ? ft_swap(a, 1) : ft_reverse_rotate(a, 1);
	else
	{
		ft_reverse_rotate(a, 1);
		ft_swap(a, 1);
	}
}
