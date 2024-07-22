#include "push_swap.h"

void	free_that(char **to_free)
{
	int	index;

	index = 0;
	if (to_free)
	{
		while (to_free[index])
		{
			free(to_free[index]);
			to_free[index] = NULL;
			index++;
		}
		free(to_free);
	}
}

t_list	*split_into_list(char *arg)
{
	t_list	*lst;
	size_t	index;
	char	**spl_arg;
 
	lst = NULL;
	index = 0;
	spl_arg = ft_split(arg, ' ');
	if (!spl_arg)
		return (NULL);
	if (check_nums(spl_arg) == -1)
	{
		free_that(spl_arg);
		ft_putendl_fd("Error", 1);
		exit(-1);
	}
	while (spl_arg[index])
		ft_lstadd_back(&lst, newlst(ft_atoi(spl_arg[index++]), &lst, spl_arg));
	free_that(spl_arg);
	return (lst);
}

t_list	*get_list(int argc, char **arg)
{
	t_list	*list;
	int		num;
	size_t	index;

	list = NULL;
	index = 1;
	if (check_nums(&arg[index]) == -1)
	{
		ft_putendl_fd("Error", 1);
		exit(-1);
	}
	while (index < (size_t)argc)
	{
		num = ft_atoi(arg[index++]);
		ft_lstadd_back(&list, ps_create_new(num, &list));
	}
	return (list);
}
