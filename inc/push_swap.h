/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:37:42 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/03 16:30:20 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct	s_s
{
	int	median;
	int max;
	int min;
	int nb1;
	int nb2;
	int nb3;
	int pushed;
	int rotated;
	int unsorted;
}				t_s;

typedef struct	s_stack
{
	char	name;
	int		elements;
	t_list	*head;
}				t_stack;

int		ft_check_n(char **av, int i);
void	ft_display_stacks(t_stack *a, t_stack *b);
void	ft_delete_stacks(t_stack *a, t_stack *b);
int		ft_fill_a(t_stack **a, int ac, char **av);
int		get_next_line(const int fd, char **line);
void	ft_swap(t_stack **s, char c, int print_mode);
void	ft_rotate(t_stack **s, char c, int print_mode);
void	ft_reverse_rotate(t_stack **s, char c, int print_mode);
void	ft_push(t_stack **s1, t_stack **s2, char c, int print_mode);
void	ft_selection_sort(t_stack **a, t_stack **b, int elements);
void	ft_insertion_sort(t_stack **a, t_stack **b, int elements);
void	ft_quicksort(t_stack **a, t_stack **b, int elements);

#endif
