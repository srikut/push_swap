/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:51:38 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/16 15:12:37 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack_node *a)
// {
// 	t_stack_node *cur;

// 	if (!a)
// 		return;
// 	cur = a;
// 	do
// 	{
// 		printf("%d ", cur->value);
// 		cur = cur->next;
// 	} while (cur != a);
// 	printf("\n");
// }
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				n;

	a = NULL;
	b = NULL;
	init_stack_node(argc, argv, &a);
	if (!a)
	{
		free_stack(&a);
		return (0);
	}
	assign_ranks(a);
	n = count_nodes(a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (n <= 5)
		sort_small(&a, &b);
	else
		radix_sort(&a, &b);
	free_stack(&a);
	return (0);
}
