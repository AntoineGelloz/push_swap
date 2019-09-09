/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/09 17:21:14 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stacks(t_stack *a, t_stack *b)
{
	t_list	*curr;

	curr = a->head;
	while (curr->next)
	{
		if (*(int *)curr->content > *(int *)curr->next->content)
			return (0);
		curr = curr->next;
	}
	if (b->head)
		return (0);
	return (1);
}

int	ft_check_line(char *line)
{
	if (line[0] == '\0' || ft_strequ(line, "Error"))
		return (0);
	else if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
			&& ft_strcmp(line, "ss") && ft_strcmp(line, "pa")
			&& ft_strcmp(line, "pb") && ft_strcmp(line, "ra")
			&& ft_strcmp(line, "rb") && ft_strcmp(line, "rr")
			&& ft_strcmp(line, "rra") && ft_strcmp(line, "rrb")
			&& ft_strcmp(line, "rrr"))
	{
		ft_putendl("Error");
		return (0);
	}
	return (1);
}

int	ft_check_instruction(char *line, t_stack *a, t_stack *b, int print_mode)
{
	if (!ft_check_line(line))
		return (0);
	(!ft_strcmp(line, "sa")) ? ft_swap(a, print_mode) : 0;
	(!ft_strcmp(line, "sb")) ? ft_swap(b, print_mode) : 0;
	(!ft_strcmp(line, "ss")) ? ft_sswap(a, b, print_mode) : 0;
	(!ft_strcmp(line, "pa")) ? ft_push(b, a, print_mode) : 0;
	(!ft_strcmp(line, "pb")) ? ft_push(a, b, print_mode) : 0;
	(!ft_strcmp(line, "ra")) ? ft_rotate(a, print_mode) : 0;
	(!ft_strcmp(line, "rb")) ? ft_rotate(b, print_mode) : 0;
	(!ft_strcmp(line, "rr")) ? ft_rrotate(a, b, print_mode) : 0;
	(!ft_strcmp(line, "rra")) ? ft_reverse_rotate(a, print_mode) : 0;
	(!ft_strcmp(line, "rrb")) ? ft_reverse_rotate(b, print_mode) : 0;
	(!ft_strcmp(line, "rrr")) ? ft_rreverse_rotate(a, b, print_mode) : 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	a.head = NULL;
	b.head = NULL;
	a.name = 'a';
	b.name = 'b';
	line = NULL;
	if (ac < 2 || (ac == 2 && ft_strequ(av[1], "-v")))
		return (0);
	if (!ft_fill_a(&a, ac, av, 1))
		return (ft_error_exit(&a));
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ(av[1], "-v"))
		{
			if (!ft_check_instruction(line, &a, &b, 1))
				break ;
			ft_display_stacks(&a, &b);
		}
		else if (!ft_check_instruction(line, &a, &b, 0))
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (ft_check_stacks(&a, &b))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_delete_stacks(&a, &b);
	return (0);
}
