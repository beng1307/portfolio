#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stk_a;
	t_list *stk_b;

	if (ac < 2)
		exit (-1);
	check_form((const char **)av);
	stk_a = NULL;
	stk_b = NULL;
	if (ac == 2)
		stk_a = split_into_list(av[1]);
	else if (ac > 2)
		stk_a = get_list(ac, (const char **)av);
	if (!stk_a)
		return (ft_lstclear(&stk_a), -1);
	if (is_sorted(stk_a))
		return (ft_lstclear(&stk_a), 0);
	sort_it(&stk_a, &stk_b);
	ft_lstclear(&stk_a);
	return (0);
}

/*

segfault with maxint
duplicate check doesnt work with 1 string

*/