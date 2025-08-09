#include "push_swap.h"

void	ra(t_stack_node **a)
{
	if(*a && (*a)->next != *a)
	{
		*a = (*a)->next;
		write(1, "ra\n", 3);
	}
}