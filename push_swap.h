#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char	**ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
void	init_stack_node(int argc, char **argv, t_stack_node **a);
void	assign_ranks(t_stack_node *a);
void	radix_sort(t_stack_node **a, t_stack_node **b);
void    sort_small(t_stack_node **a, t_stack_node **b);
int     is_sorted(t_stack_node *a);
int	count_nodes(t_stack_node *a);
void    sa(t_stack_node **a);
void    sb(t_stack_node **b);
void    rra(t_stack_node **a);
void    rrb(t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
void	ra(t_stack_node **a);

#endif