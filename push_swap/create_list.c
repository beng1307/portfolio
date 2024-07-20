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

t_list	*split_into_list(const char *arg)
{
	t_list	*lst;
	char	**spl_arg;
	char	**temp;
 
	lst = NULL;
	spl_arg = ft_split(arg, ' ');
	if (!spl_arg)
		return (NULL);
	temp = spl_arg;
	check_nums((const char **)spl_arg);
	while (*spl_arg)
	{
		ft_lstadd_back(&lst, newlst(ft_atoi(*spl_arg), &lst, spl_arg, temp));
		spl_arg++;
	}
	free_that(temp);
	return (lst);
}

t_list	*get_list(int argc, const char **arg)
{
	t_list	*list;
	int		num;
	size_t	index;

	list = NULL;
	index = 1;
	check_nums(&arg[index]);
	while (index < (size_t)argc)
	{
		num = ft_atoi(arg[index++]);
		ft_lstadd_back(&list, ps_create_new(num, &list));
	}
	return (list);
}
