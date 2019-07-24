/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/24 14:51:08 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int		ft_check(t_stack *a, t_stack *b)
{
	t_number	*curr;

	curr = a->first;
	while (curr->next)
	{
		if (curr->n > curr->next->n)
			return (0);
		curr = curr->next;
	}
	if (b->first)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char 		*line;

	if (!(a = malloc(sizeof(*a))) || !(b = malloc(sizeof(*b))))
		return (0);
	a->first = NULL;
	b->first = NULL;
	line = NULL;
	if (ac < 2 || !ft_fill_a(&a, ac, av))
		return (0);
	ft_display_stacks(a, b);
	ft_putchar('\n');
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "sa") == 0)
			ft_swap(&a);
		else if (ft_strcmp(line, "sb") == 0)
			ft_swap(&b);
		else if (ft_strcmp(line, "ss") == 0)
		{
			ft_rotate(&a);
			ft_rotate(&b);
		}
		else if (ft_strcmp(line, "pa") == 0)
			ft_push(&a, &b);
		else if (ft_strcmp(line, "pb") == 0)
			ft_push(&b, &a);
		else if (ft_strcmp(line, "ra") == 0)
			ft_rotate(&a);
		else if (ft_strcmp(line, "rb") == 0)
			ft_rotate(&b);
		else if (ft_strcmp(line, "rr") == 0)
		{
			ft_rotate(&a);
			ft_rotate(&b);
		}
		else if (ft_strcmp(line, "rra") == 0)
			ft_reverse_rotate(&a);
		else if (ft_strcmp(line, "rrb") == 0)
			ft_reverse_rotate(&a);
		else if (ft_strcmp(line, "rrr") == 0)
		{
			ft_reverse_rotate(&a);
			ft_reverse_rotate(&b);
		}
		else if (line[0] == '\0')
			break ;
		else
		{
			ft_putstr("Error\n.");
			break ;
		}
	}
	ft_strdel(&line);
	if (ft_check(a, b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_display_stacks(a, b);
	ft_delete_stacks(a, b);
	return (0);
}
