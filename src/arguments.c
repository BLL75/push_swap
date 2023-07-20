/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:55:54 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 00:27:30 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*allocate_memory(int total_length)
{
	char	*input;

	input = malloc(sizeof(char) * (total_length + 1));
	if (input == NULL)
		exit(EXIT_FAILURE);
	input[0] = '\0';
	return (input);
}

char	*concatenate_arguments(int argc, char *argv[])
{
	int		total_length;
	int		i;
	char	*input;

	total_length = 0;
	i = 1;
	while (i < argc)
	{
		total_length += ft_strlen(argv[i]) + 1;
		i++;
	}
	input = allocate_memory(total_length);
	i = 1;
	while (i < argc)
	{
		ft_strcat (input, argv[i]);
		if (i != argc - 1)
			ft_strcat (input, " ");
		i++;
	}
	return (input);
}

void	error_and_exit(char *input, t_stack **stack_a)
{
	write(1, "Error\n", 6);
	free(input);
	free_stack(stack_a);
	exit(EXIT_FAILURE);
}

void	process_arguments(char *input, t_stack **stack_a)
{
	char	*token;
	int		num;

	if (input[0] == '"' && input[ft_strlen(input) - 1] == '"')
		token = ft_strtok(input + 1, "\"");
	else
		token = ft_strtok(input, " ");
	while (token != NULL)
	{
		if (!is_valid(token))
			error_and_exit(input, stack_a);
		num = ft_atoi(token);
		is_duplicate(stack_a, num);
		push(stack_a, num);
		if (input[0] == '"' && input[ft_strlen(input) - 1] == '"')
			token = ft_strtok(NULL, "\"");
		else
			token = ft_strtok(NULL, " ");
	}
}
