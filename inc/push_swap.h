/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:37:42 by agelloz           #+#    #+#             */
/*   Updated: 2019/07/25 17:14:37 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef	struct	s_number
{
	int				n;
	struct s_number	*next;

}				t_number;

typedef struct	s_stack
{
	t_number	*first;
}				t_stack;

int		ft_check_n(char **av, int i);
void	ft_display_stacks(t_stack *a, t_stack *b);
void	ft_delete_stacks(t_stack *a, t_stack *b);
int		ft_fill_a(t_stack **a, int ac, char **av);
int		get_next_line(const int fd, char **line);
t_stack	*ft_swap(t_stack **s);
t_stack	*ft_rotate(t_stack **s);
t_stack *ft_reverse_rotate(t_stack **s);
t_stack *ft_push(t_stack **s1, t_stack **s2);
void	ft_selection_sort(t_stack **a, t_stack **b, int n);
void	ft_insertion_sort(t_stack **a, t_stack **b, int elements);

#endif
