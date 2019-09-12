/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/12 16:05:11 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_stacks(t_stack *a, t_stack *b)
{
	t_list	*curr;

	curr = a->head;
	while (curr && curr->next)
	{
		if (*(int *)curr->content > *(int *)curr->next->content)
			return (0);
		curr = curr->next;
	}
	if (b->head)
		return (0);
	return (1);
}

int		ft_check_line(char *line)
{
	if (line[0] == '\0' || ft_strequ(line, "Error"))
		return (0);
	else if (ft_strcmp(line, "sa\n") && ft_strcmp(line, "sb\n")
			&& ft_strcmp(line, "ss\n") && ft_strcmp(line, "pa\n")
			&& ft_strcmp(line, "pb\n") && ft_strcmp(line, "ra\n")
			&& ft_strcmp(line, "rb\n") && ft_strcmp(line, "rr\n")
			&& ft_strcmp(line, "rra\n") && ft_strcmp(line, "rrb\n")
			&& ft_strcmp(line, "rrr\n"))
	{
		ft_putendl("Error");
		return (0);
	}
	return (1);
}

void	ft_exec_instruction(char *line, t_stack *a, t_stack *b, int print_mode)
{
	(!ft_strcmp(line, "sa\n")) ? ft_swap(a, print_mode) : 0;
	(!ft_strcmp(line, "sb\n")) ? ft_swap(b, print_mode) : 0;
	(!ft_strcmp(line, "ss\n")) ? ft_sswap(a, b, print_mode) : 0;
	(!ft_strcmp(line, "pa\n")) ? ft_push(b, a, print_mode) : 0;
	(!ft_strcmp(line, "pb\n")) ? ft_push(a, b, print_mode) : 0;
	(!ft_strcmp(line, "ra\n")) ? ft_rotate(a, print_mode) : 0;
	(!ft_strcmp(line, "rb\n")) ? ft_rotate(b, print_mode) : 0;
	(!ft_strcmp(line, "rr\n")) ? ft_rrotate(a, b, print_mode) : 0;
	(!ft_strcmp(line, "rra\n")) ? ft_reverse_rotate(a, print_mode) : 0;
	(!ft_strcmp(line, "rrb\n")) ? ft_reverse_rotate(b, print_mode) : 0;
	(!ft_strcmp(line, "rrr\n")) ? ft_rreverse_rotate(a, b, print_mode) : 0;
}

int		ft_process_line(t_stack *a, t_stack *b, char *line, char *av1)
{
	if (line && !ft_check_line(line))
	{
		ft_delete_stacks(a, b);
		ft_strdel(&line);
		return (0);
	}
	if (ft_strequ(av1, "-v"))
	{
		ft_exec_instruction(line, a, b, 1);
		ft_display_stacks(a, b);
	}
	else
		ft_exec_instruction(line, a, b, 0);
	return (1);
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*line;
	int		ret;

	a.head = NULL;
	b.head = NULL;
	a.name = 'a';
	b.name = 'b';
	line = NULL;
	if (ac < 2 || (ac == 2 && ft_strequ(av[1], "-v")))
		return (0);
	if (!ft_fill_a(&a, ac, av, 1))
		return (ft_error_exit(&a));
	while ((ret = get_next_line(0, &line)) > 0)
	{
		//ft_printf("|%s|\n", line);
		if (!ft_process_line(&a, &b, line, av[1]))
			return (0);
	}
		if (ft_check_stacks(&a, &b))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_delete_stacks(&a, &b);
	ft_strdel(&line);
	return (0);
}
