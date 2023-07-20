/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:01:00 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 12:01:11 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack **stack, int num)
{
	t_stack		*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->value == num)
		{
			write(1, "Error\n", 6);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
	return (0);
}

int	is_valid(const char *str)
{
	int	i;

	i = 0;
	if (*str == '\0' || *str == ' ')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
