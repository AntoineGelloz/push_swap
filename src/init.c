/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/12 14:53:51 by agelloz          ###   ########.fr       */
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
	else if (*tmp == '+')
		tmp++;
	if (!*tmp)
		return (0);
	return (ft_check_n2(av, tmp, neg, i));
}

int		ft_fill_a(t_stack *a, int ac, char **av, int checker)
{
	t_list	*curr;
	int		i;
	int		num;

	i = 0;
	if (checker && ft_strequ(av[1], "-v"))
		i++;
	while (++i < ac)
	{
		if (!ft_check_n(av, i))
		{
			ft_putendl("Error");
			return (0);
		}
		num = ft_atoi(av[i]);
		if (!(curr = ft_lstnew(&num, sizeof(int))))
			return (0);
		ft_lstprepend(&a->head, curr);
	}
	ft_lstrev(&a->head);
	a->elements = ac - 1;
	return (1);
}
