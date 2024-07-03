#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    t_list  *lastlst;

    if (!lst)
        return (NULL);
    lastlst = lst;
    while (lastlst->next != NULL)
        lastlst = lastlst->next;
    return (lastlst);
}