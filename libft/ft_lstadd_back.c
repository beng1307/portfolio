#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *lastlst;

    if (lst && new)
    {
		lastlst = *lst;
		while (lastlst->next != NULL)
        	lastlst = lastlst->next;
        lastlst->next = new;
    }
}