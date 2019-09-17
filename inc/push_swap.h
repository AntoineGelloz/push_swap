/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:37:42 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/16 15:47:10 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "printf.h"

typedef struct	s_s
{
	int	initial_elements;
	int unsorted;
	int pushed;
	int rotated;
	int	median;
	int max;
	int min;
	int nb1;
	int nb2;
	int nb3;
}				t_s;

typedef struct	s_stack
{
	t_list	*head;
	int		elements;
	char	name;
	char	pad[3];
}				t_stack;

int				ft_check_n(char **av, int i);
void			ft_display_stacks(t_stack *stack1, t_stack *stack2);
int				ft_fill_a(t_stack *a, int ac, char **av, int checker);
int				ft_get_next_line(const int fd, char **line);
void			ft_push(t_stack *src, t_stack *dst, int print_mode);
void			ft_swap(t_stack *s, int print_mode);
void			ft_sswap(t_stack *a, t_stack *b, int print_mode);
void			ft_rotate(t_stack *s, int print_mode);
void			ft_rrotate(t_stack *a, t_stack *b, int print_mode);
void			ft_reverse_rotate(t_stack *s, int print_mode);
void			ft_rreverse_rotate(t_stack *a, t_stack *b, int print_mode);
void			ft_sort_sublist(t_stack *stack1, t_stack *stack2, t_s *s,
		int elements);
void			ft_sort_a(t_stack *a, t_stack *b, t_s *s);
void			ft_sort_b(t_stack *a, t_stack *b, t_s *s);
void			ft_sort_only3_a(t_stack *a, t_s *s);
void			ft_sort_only3_b(t_stack *b, t_s *s);
int				ft_error_exit(t_stack *a);
void			ft_delete_stacks(t_stack *a, t_stack *b);
void			ft_update_s(t_stack *stack, t_s *s, int elements);
void			ft_sort_top3(t_stack *stack1, t_stack *stack2, t_s *s,
								int elements);
int				ft_is_sorted(t_stack *stack1, t_stack *stack2, int elements);

#endif
