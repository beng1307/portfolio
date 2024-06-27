#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *lastlst;

    if (*lst)
	{
    	lastlst = ft_lstlast(*lst);
    	lastlst->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}