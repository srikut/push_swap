/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:48:52 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/15 14:48:53 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rra(t_stack_node **a)
{
	if (a && *a && (*a)->next != *a)
	{
		*a = (*a)->prev;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack_node **b)
{
	if (b && *b && (*b)->next != *b)
	{
		*b = (*b)->prev;
		write(1, "rrb\n", 4);
	}
}
