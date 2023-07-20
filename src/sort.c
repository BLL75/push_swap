/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:56:19 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 00:18:25 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	x;
	int	y;
	int	z;

	x = (*stack_a)->value;
	y = (*stack_a)->next->value;
	z = (*stack_a)->next->next->value;
	if (y > z && z > x)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (z > x && x > y)
		sa(stack_a);
	else if (y > x && x > z)
		rra(stack_a);
	else if (x > y && y > z)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (x > z && z > y)
		ra(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	while ((*stack_a)->value != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	while ((*stack_a)->value != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	min = find_min(*stack_a);
	while ((*stack_a)->value != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		indexing_stack(stack_a);
		radix_sort(stack_a, stack_b);
	}	
	return (1);
}
