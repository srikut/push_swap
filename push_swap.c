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

// int	main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;

// 	init_stack_node(argc, argv, &a);
// 	if (!a)
// 		return (0);

// 	assign_ranks(a);
// 	radix_sort(&a, &b);

// 	// print_stack(a);
// 	return (0);
// }

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;
    int n;

    init_stack_node(argc, argv, &a);
    if (!a) return 0;

    assign_ranks(a);
    n = count_nodes(a);

    if (n <= 5)
        sort_small(&a, &b);
    else
        radix_sort(&a, &b);

    return 0;
}
