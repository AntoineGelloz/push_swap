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

int		ft_error_exit(t_stack *a)
{
	ft_lstdel(&a->head, ft_delcontent);
	return (0);
}

void	ft_delete_stacks(t_stack *a, t_stack *b)
{
	ft_lstdel(&a->head, ft_delcontent);
	ft_lstdel(&b->head, ft_delcontent);
}
