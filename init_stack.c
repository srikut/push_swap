#include "push_swap.h"

void	init_stack_node(int argc, char **argv, t_stack_node **a);
static void	push_node(t_stack_node **stack, const char *str);
static t_stack_node	*create_node(const char *str);

void	init_stack_node(int argc, char **argv, t_stack_node **a)
{
	char	**args;
	int		i;

	if (argc < 2)
		exit (0);
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		push_node(a, args[i]);
		i++;
	}
	if (argc == 2)
		free(args);//ここでメモリーリクの恐れあり
}

static void	push_node(t_stack_node **stack, const char *str)
{
	t_stack_node	*new_node;
	t_stack_node	*tail;

	new_node = create_node(str);
	/*空のリストだった場合*/
	if (*stack == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*stack = new_node;
	}
	else
	{
		tail = (*stack)->prev;//末尾のリストの取得
		new_node->next = *stack;
		new_node->prev = tail;
		tail->next = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;//新しいのーどを先頭に追加
	}
}

static t_stack_node	*create_node(const char *str)
{
	t_stack_node	*node;
	int				num;

	num = ft_atoi(str);
	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		exit (1);
	node->value = num;
	node->rank = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
