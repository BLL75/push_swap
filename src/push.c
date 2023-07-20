/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:55:39 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 16:01:43 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to(t_stack **sourceStack, t_stack **destinationStack)
{
	t_stack		*head_from;
	t_stack		*temp;
	t_stack		*head_to;

	if (!sourceStack)
		return (-1);
	head_from = *sourceStack;
	temp = head_from;
	*sourceStack = head_from->next;
	if (!destinationStack)
	{
		temp->next = NULL;
		*destinationStack = temp;
	}
	else
	{
		head_to = *destinationStack;
		temp->next = head_to;
		*destinationStack = temp;
	}
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push_to(stack_b, stack_a) == -1)
	{
		return (-1);
	}
	write (1, "pa\n", 3);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push_to(stack_a, stack_b) == -1)
		return (-1);
	write (1, "pb\n", 3);
	return (0);
}
