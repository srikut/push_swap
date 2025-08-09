#include "push_swap.h"
#include <unistd.h>

static void swap_top_two(t_stack_node **s)
{
    t_stack_node *x, *y;
    int tv, tr;

    if (!s || !*s || (*s)->next == *s)
        return;
    x = *s;
    y = x->next;

    tv = x->value; x->value = y->value; y->value = tv;
    tr = x->rank;  x->rank  = y->rank;  y->rank  = tr;
}

void sa(t_stack_node **a)
{
    swap_top_two(a);
    write(1, "sa\n", 3);
}

void sb(t_stack_node **b)
{
    swap_top_two(b);
    write(1, "sb\n", 3);
}
