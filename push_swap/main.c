#include "libft.h"

int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;

    if (ac < 2)
        return (ft_putendl_fd ("Error", 2), -1);
	sort_it(stack_a, stack_b);
	

	return (0);
}