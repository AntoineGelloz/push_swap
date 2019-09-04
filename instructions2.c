/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:42:35 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/04 18:43:22 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *current, int print_mode)
{
	if (ft_lstcount(current->head) >= 2)
		ft_lstrotate(&current->head);
	if (verbose)
		ft_printf("r%c\n", ft_tolower(STACK));
}

void	ft_rrotate(t_stack *a, t_stack *b, int print_mode)
{
	rotate(a, 0);
	rotate(b, 0);
	if (verbose)
		ft_putendl("rr");
}

void	ft_reverse_rotate(t_stack *current, int print_mode)
{
	if (ft_lstcount(current->head) >= 2)
		ft_lstrevrotate(&current->head);
	if (verbose)
		ft_printf("rr%c\n", ft_tolower(STACK));
}

void	ft_rreverse_rotate(t_stack *a, t_stack *b, int print_mode)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	if (verbose)
		ft_putendl("rrr");
}
