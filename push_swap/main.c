#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;

	check_args(ac, (const char **)av);
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		stack_a = split_into_list(av[1]);
	else if (ac > 2)
		stack_a = get_list(ac, (const char **)av);
	if (!stack_a)
		return (ft_putendl_fd ("Error", 1), -1);
	if (is_sorted(stack_a))
		return (ft_lstclear(&stack_a), 0);
	sort_it(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
