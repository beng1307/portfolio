#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;

	if (ac < 2)
		exit (-1);
	check_form((const char **)av);
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		stack_a = split_into_list(av[1]);
	else if (ac > 2)
		stack_a = get_list(ac, (const char **)av);
	if (!stack_a)
		return (ft_lstclear(&stack_a), -1);
	if (is_sorted(stack_a))
		return (ft_lstclear(&stack_a), 0);
	sort_it(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}

/*

segfault with maxint
duplicate check doesnt work with 1 string

*/