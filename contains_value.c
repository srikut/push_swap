/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:55:26 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/16 08:59:57 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_value(t_stack_node *a, int v)
{
	int				n;
	int				i;
	t_stack_node	*cur;

	if (!a)
		return (0);
	n = count_nodes(a);
	cur = a;
	i = 0;
	while (i < n)
	{
		if (cur->value == v)
			return (1);
		cur = cur->next;
		i++;
	}
	return (0);
}
