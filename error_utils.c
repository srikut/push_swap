/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:58:29 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/16 13:55:35 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	free_stack(t_stack_node **stack)
{
    t_stack_node	*cur;
    t_stack_node	*next;

	if (!stack || !*stack)
		return ;
	cur = (*stack)->next;
	while (cur != *stack)
	{
		next = cur->next;
		free (cur);
		cur = next;
	}
	free (*stack);
	*stack = NULL;
}

void	free_split(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return ;	
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
