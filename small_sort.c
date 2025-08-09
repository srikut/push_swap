#include "push_swap.h"

// 昇順確認（rankで判定）
int is_sorted(t_stack_node *a)
{
    t_stack_node *cur;
    if (!a || a->next == a) return 1;
    cur = a;
    do {
        if (cur->rank > cur->next->rank) return 0;
        cur = cur->next;
    } while (cur != a);
    return 1;
}

static int index_of_min(t_stack_node *a)
{
    int pos = 0, best_pos = 0;
    int best = a->rank;
    t_stack_node *cur = a->next;

    while (cur != a) {
        pos++;
        if (cur->rank < best) { best = cur->rank; best_pos = pos; }
        cur = cur->next;
    }
    return best_pos; // 0-based
}

static void rotate_to_top(t_stack_node **a, int pos, int size)
{
    int i = 0;
    if (pos <= size / 2) {
        while (i < pos) { ra(a); i++; }
    } else {
        while (i < size - pos) { rra(a); i++; }
    }
}

static void sort_three(t_stack_node **a)
{
    int x, y, z;

    if (is_sorted(*a)) return;

    x = (*a)->rank;
    y = (*a)->next->rank;
    z = (*a)->next->next->rank;

    if (x > y && y < z && x < z)               sa(a);         // 2 1 3
    else if (x > y && y > z) {                 sa(a); rra(a);} // 3 2 1
    else if (x > y && y < z && x > z)          ra(a);          // 3 1 2
    else if (x < y && y > z && x < z) {        sa(a); ra(a);}  // 1 3 2
    else if (x < y && y > z && x > z)          rra(a);         // 2 3 1
    // 残りは既に整列
}

void sort_small(t_stack_node **a, t_stack_node **b)
{
    int n = count_nodes(*a);

    if (is_sorted(*a)) return;

    if (n == 2) {
        if ((*a)->rank > (*a)->next->rank) sa(a);
        return;
    }
    if (n == 3) { sort_three(a); return; }

    // n == 4 or 5
    while (count_nodes(*a) > 3) {
        int size = count_nodes(*a);
        int pos = index_of_min(*a);
        rotate_to_top(a, pos, size);
        pb(a, b);
    }
    sort_three(a);
    while (*b) pa(a, b); // 抜いた最小群を戻すだけで昇順が完成
}
