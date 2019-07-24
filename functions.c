/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/24 11:15:19 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_n(char **av, int i)
{
	int		j;
	int		neg;
	char	*tmp;

	tmp = av[i];
	neg = 0;
	if (*tmp == '-')
	{
		neg = 1;
		tmp++;
	}
	j = 0;
	if (!*tmp)
		return (0);
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
			curr = NULL;
			curr = a->first;
		}
		free(a);
		a = NULL;
	}
	if (b)
	{
		curr = b->first;
		while (curr)
		{
			b->first = b->first->next;
			free(curr);
			curr = NULL;
			curr = b->first;
		}
		free(b);
		b = NULL;
	}
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

t_stack	*ft_swap(t_stack **s)
{
	t_number	*one;
	t_number	*two;

	one = (**s).first;
	if (one->next)
	{
		two = one->next;
		one->next = (two->next) ? two->next : NULL;
		two->next = one;
		(**s).first = two;
	}
	return (*s);
}

t_stack	*ft_rotate(t_stack **s)
{
	t_number	*one;
	t_number	*curr;

	one = (**s).first;
	curr = (**s).first;
	while (curr->next)
		curr = curr->next;
	((**s).first->next) ? (**s).first = (**s).first->next : 0;
	curr->next = one;	
	curr->next->next = NULL;
	return (*s);
}

t_stack	*ft_reverse_rotate(t_stack **s)
{
	t_number	*one;
	t_number	*curr;

	one = (**s).first;
	curr = (**s).first;
	while (curr->next->next)
		curr = curr->next;
	(**s).first = curr->next;
	curr->next->next = one;
	curr->next = NULL;
	return (*s);
}

t_stack	*ft_push(t_stack **s1, t_stack **s2)
{
	t_number	*one;
	t_number	*pushed;

	if ((**s2).first)
	{
		one = (**s1).first;
		pushed = (**s2).first;
		(**s1).first = pushed;
		(**s2).first = pushed->next;
		pushed->next = one;
	}
	return (*s1);
}

void	ft_display_stacks(t_stack *a, t_stack *b)
{
	t_number	*curr;

	curr = a->first;
	ft_putstr("a");
	ft_putchar('|');
	while (curr)
	{
		if (curr != a->first)
			ft_putchar(' ');
		ft_putnbr(curr->n);
		curr = curr->next;
	}
	ft_putchar('|');
	//ft_putchar('\n');
	curr = (b->first) ? b->first : NULL;
	ft_putstr(" b");
	ft_putchar('|');
	while (curr)
	{
		if (curr != b->first)
			ft_putchar(' ');
		ft_putnbr(curr->n);
		curr = curr->next;
	}
	ft_putchar('|');
}
