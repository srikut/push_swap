/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:32:13 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/16 13:56:19 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
void	init_stack_node(int argc, char **argv, t_stack_node **a);
void	assign_ranks(t_stack_node *a);
void	radix_sort(t_stack_node **a, t_stack_node **b);
int		is_sorted(t_stack_node *a);
int		count_nodes(t_stack_node *a);
void	quick_sort(int *n, int left, int right);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
void	ra(t_stack_node **a);

//small_sort
void	sort_small(t_stack_node **a, t_stack_node **b);
int		index_of_min(t_stack_node *a);
void	rotate_to_top(t_stack_node **a, int pos, int size);
void	sort_three(t_stack_node **a);

//error handling
void	error_exit(void);
int		is_num(char **argv);
int		contains_value(t_stack_node *a, int v);
void	free_stack(t_stack_node **stack);
void	free_split(char **arr);

#endif