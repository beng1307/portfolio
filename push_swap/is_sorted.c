#include "libft.h"

int	is_sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{	
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}