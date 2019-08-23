/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/29 16:37:37 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_n2(char **av, char *tmp, int neg, int i)
{
	int j;

	j = 0;
	while (*tmp)
	{
		j++;
		if (*tmp < '0' || *tmp > '9' || j > 10)
			return (0);
		tmp++;
	}
	if (j == 10 && ((neg && ft_strcmp(av[i] + 1, "2147483648") > 0)
				|| (!neg && ft_strcmp(av[i], "2147483647") > 0)))
		return (0);
	while (i > 1)
	{
		j = i - 1;
		while (j > 0)
			if (ft_strcmp(av[i], av[j--]) == 0)
				return (0);
		i--;
	}
	return (1);
}

int		ft_check_n(char **av, int i)
{
	int		neg;
	char	*tmp;

	tmp = av[i];
	neg = 0;
	if (*tmp == '-')
	{
		neg = 1;
		tmp++;
	}
	if (!*tmp)
		return (0);
	return (ft_check_n2(av, tmp, neg, i));
}

void	ft_delete_stacks(t_stack *a, t_stack *b)
{
	t_number	*curr;

	if (a)
	{
		curr = a->first;
		while (curr)
		{
			a->first = a->first->next;
			free(curr);
			curr = a->first;
		}
		free(a);
		a = NULL;
	}
	if (!b)
		return ;
	curr = b->first;
	while (curr)
	{
		b->first = b->first->next;
		free(curr);
		curr = b->first;
	}
	free(b);
	b = NULL;
}

int		ft_fill_a(t_stack **a, int ac, char **av)
{
	t_number	*curr;
	t_number	*prev;
	int			i;

	i = 0;
	while (++i < ac)
	{
		if (ft_check_n(av, i))
		{
			if (!(curr = malloc(sizeof(*curr))))
				return (0);
			(i != 1) ? prev->next = curr : 0;
			curr->n = ft_atoi(av[i]);
			curr->index = i - 1;
			curr->next = NULL;
			(i == 1) ? (**a).first = curr : 0;
			prev = curr;
			curr = curr->next;
		}
		else
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	return (1);
}
