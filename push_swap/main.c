#include "push_swap.h"

void	check_args(int ac, const char **av)
{
	const char	*arg;
	size_t		index;

	index = 1;
	if (ac < 2)
	{
		ft_putendl_fd("Error", 1);
		exit(-1);
	}
	while (av[index])
	{
		arg = av[index++];
		while (*arg)
 		{
			if (!(ft_isdigit(*arg) || *arg == ' ' || *arg == '-')
				|| (*arg == '-' && ft_isdigit(*(arg + 1)) != 1))
			{
				ft_putendl_fd("Error", 1);
				exit(-1);
			}
			arg++;
		}
	}
}

t_list	*split_into_list(const char *arg)
{
	t_list	*list;
	char	**splitted_arg;
 
	list = NULL;
	splitted_arg = ft_split(arg, ' ');
	if (!splitted_arg)
		return (NULL);
	while (*splitted_arg)
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(*splitted_arg++)));
	if (!list)
		return (ft_lstclear(&list), NULL);
	return (list);
}

t_list	*get_list(int argc, const char **arg)
{
	int		num;
	t_list	*list;
	size_t	index;

	list = NULL;
	index = 1;
	while (index < (size_t)argc)
	{
		num = ft_atoi(arg[index++]);
		ft_lstadd_back(&list, ft_lstnew(num));
	}
	if (!list)
		return (ft_lstclear(&list), NULL); 
	return (list);
}

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
	sort_it(&stack_a, &stack_b);
	if (!is_sorted(stack_a) || stack_b)
		ft_putendl_fd("Is not sorted!", 1);
	ft_lstclear(&stack_a);
	return (0);
}

/*
*/