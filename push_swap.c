/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:47:24 by srikuto           #+#    #+#             */
/*   Updated: 2025/08/10 15:48:58 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	init_stack_node(argc, argv, &a);
	if (!a)
		return (0);
	assign_ranks(a);
	radix_sort(&a, &b);
	return (0);
}
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
