#include "libft.h"

int	is_sorted(t_list *stack)
{
	t_list	*test;

	test = stack;
	while (test && test->next)
	{	
		if ((test)->content > (test)->next->content)
			return (0);
		test = test->next;
	}
	return (1);
}