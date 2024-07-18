#include "push_swap.h"

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
