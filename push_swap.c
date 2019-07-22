/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/22 16:46:48 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

typedef	struct		s_number
{
	int				n;
	struct s_number	*next;

}					t_number;

typedef struct		s_stack
{
	t_number *first;
}					t_stack;

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

void	ft_delete_stack(t_stack *s)
{
	t_number	*curr;

	curr = s->first;
	while (curr)
	{
		s->first = s->first->next;
		free(curr);
		curr = NULL;
		curr = s->first;
	}
	free(s);
	s = NULL;
}

t_stack	*ft_fill_a(int ac, char **av)
{
	t_stack		*a;
	t_number	*curr;
	t_number	*prev;
	int			i;

	if (!(a = malloc(sizeof(*a))))
		return (NULL);
	i = 0;
	while (++i < ac)
	{
		if (ft_check_n(av, i))
		{
			if (!(curr = malloc(sizeof(*curr))))
				return (NULL);
			(i != 1) ? prev->next = curr : 0;
			curr->n = ft_atoi(av[i]);
			curr->next = NULL;
			(i == 1) ? a->first = curr : 0;
			prev = curr;
			curr = curr->next;
		}
		else
		{
			ft_putstr("Error\n");
			ft_delete_stack(a);
			return (NULL);
		}
	}
	return (a);
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

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_number	*curr;

	if (ac < 2 || !(a = ft_fill_a(ac, av)))
		return (0);
	a = ft_swap(&a);
	curr = a->first;
	b = NULL;
	ft_putstr("Stack a:\n");
	while (curr)
	{
		ft_putnbr(curr->n);
		ft_putchar('\n');
		curr = curr->next;
	}
	ft_delete_stack(a);
	return (0);
}
