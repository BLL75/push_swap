/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:56:51 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 00:14:17 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return ;
	}
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		return ;
	}
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
