/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:15:06 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/09 17:12:49 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_exit(t_stack *a)
{
	ft_lstdel(&a->head, ft_delcontent);
	a->head = NULL;
	return (0);
}

void	ft_delete_stacks(t_stack *a, t_stack *b)
{
	if (a->head)
		ft_lstdel(&a->head, ft_delcontent);
	if (b->head)
		ft_lstdel(&b->head, ft_delcontent);
	a->head = NULL;
	b->head = NULL;
}
