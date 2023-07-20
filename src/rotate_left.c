/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:41:50 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 12:02:51 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack		*head;
	t_stack		*current;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	head = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	current = head;
	while (current->next != NULL)
		current = current->next;
	head->next = NULL;
	current->next = head;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*current;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	head = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	current = head;
	while (current->next != NULL)
		current = current->next;
	head->next = NULL;
	current->next = head;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
