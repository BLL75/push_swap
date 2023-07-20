/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rigth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:56:09 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 00:19:08 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **head)
{
	t_stack	*current;
	t_stack	*last;

	current = *head;
	if (current == NULL || current->next == NULL)
		return ;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	last = current->next;
	current->next = NULL;
	last->next = *head;
	*head = last;
	write (1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		return ;
	}
	last = *stack_b;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
