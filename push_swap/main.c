#include "libft.h"

void	check_args(int ac, const char **av)
{
	if (ac < 2)
	{
		ft_putendl_fd ("Error", 2);
		exit (-1);
	}
	while (**av)
	{
		while (*av)
		{
			if ()
		}
	}
}

t_list	*split_into_list(const char *arg)
{
	t_list	*list;
	char	**splitted_arg;

	*splitted_arg = ft_split(arg, ' ');
	if (!*splitted_arg)
		return (NULL);
	while (**splitted_arg)
		ft_lstadd_back(&list, ft_lstnew(**splitted_arg++));
	return (list);
}

t_list	*get_list(int argc, const char **arg)
{
	t_list	*list;
	size_t	index;

	index = 1;
	while (index < argc)
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(arg[index++])));
	if (!list)
		return (ft_lstclear(&list)); 
	return (list);
}

void	sort_it(t_list *stack_a, t_list *stack_b)
{
/*
	while (1)
	{
		if (is_sorted(stack_a, stack_b) == 1 && !stack_b)
			return ;
		if (stack_a->content > stack_a->next->content)
			sa(stack_a);
		else if (stack_b->content )
	}
*/	
}

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;

	check_args(ac, **av);
	if (ac == 2)
	{
		stack_a = split_into_list(*av[1]);
		if (!stack_a)
			return (ft_putendl_fd ("Error", 2), -1);
		stack_b = NULL;
	}
	else if (ac > 2)
	{
		stack_a = get_list(ac, *av);
		stack_b = NULL;
	}
	sort_it(stack_a, stack_b);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	return (0);
}

/*

I have to change the lstclear function.

*/