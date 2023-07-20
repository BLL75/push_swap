/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:56:30 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 12:06:48 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	if (stack == NULL)
		return (INT_MAX);
	min = stack->value;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

t_stack	*reverse_stack(t_stack *stack)
{
	t_stack		*prev;
	t_stack		*current;
	t_stack		*next;

	prev = NULL;
	current = stack;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

int	get_stack_size(t_stack *stack)
{
	int			i;
	t_stack		*head;

	i = 0;
	head = stack;
	while (head)
	{
		i++;
		head = head-> next;
	}
	return (i);
}

int	is_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	cleanup(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}
