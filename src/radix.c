/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:55:47 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 16:42:06 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack	*get_next_min(t_stack *stack)
{
	int		found;
	t_stack	*min;
	t_stack	*current;

	current = stack;
	found = 0;
	min = NULL;
	if (current)
	{
		while (current)
		{
			if ((current->index == -1)
				&& (!found || current->value < min->value))
			{
				min = current;
				found = 1;
			}
			current = current-> next;
		}
	}
	return (min);
}

void	indexing_stack(t_stack **stack_ptr)
{
	int		idx;
	t_stack	*min_unidx;

	idx = 0;
	min_unidx = get_next_min(*stack_ptr);
	while (min_unidx != NULL)
	{
		min_unidx->index = idx++;
		min_unidx = get_next_min(*stack_ptr);
	}
}

static int	get_max_bits(t_stack *stack)
{
	int		max_index;
	int		max_bits;
	t_stack	*current_element;

	current_element = stack;
	max_index = current_element-> index;
	max_bits = 0;
	while (current_element)
	{
		if (max_index < current_element-> index)
			max_index = current_element-> index;
		current_element = current_element-> next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		stack_size;
	int		max_bits;
	int		bit_idx;
	int		element_idx;
	t_stack	*current_element;

	current_element = *stack_a;
	stack_size = get_stack_size(*stack_a);
	max_bits = get_max_bits(*stack_a);
	bit_idx = 0;
	while (bit_idx < max_bits)
	{
		element_idx = 0;
		while (element_idx++ < stack_size)
		{
			current_element = *stack_a;
			if (((current_element->index >> bit_idx) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (get_stack_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		bit_idx++;
	}
}
