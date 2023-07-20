/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:57:54 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/20 22:07:41 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}	t_stack;

// arguments.c
char	*allocate_memory(int total_length);
char	*concatenate_arguments(int argc, char *argv[]);
void	error_and_exit(char *input, t_stack **a);
void	process_arguments(char *input, t_stack **a);

// control.c
int		is_duplicate(t_stack **stack, int num);
int		is_valid(const char *str);

// push.c
int		push_to(t_stack **sourceStack, t_stack **destinationStack);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		pop(t_stack **stack);

// radix.c
void	indexing_stack(t_stack **stack_ptr);
void	radix_sort(t_stack **a, t_stack **b);

// rotate_left.c
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// rotate_right.c
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// sort.c
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
int		sort_stack(t_stack **a, t_stack **b, int size);

// stack_utils.c
void	print_stack(t_stack *a);
int		find_min(t_stack *stack);
int		get_stack_size(t_stack *stack);
t_stack	*reverse_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

// stack.c
void	push(t_stack **stack, int value);
void	free_stack(t_stack **stack);
void	cleanup(t_stack **a, t_stack **b);

// swap.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif
