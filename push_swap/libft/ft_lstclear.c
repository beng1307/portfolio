#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *to_clear;

    if (!(lst == NULL || del == NULL))
    {
        to_clear = *lst;
        while (to_clear != NULL)
        {   
            to_clear = to_clear->next;
            del((*lst)->content);
            free(*lst);
            *lst = to_clear;
        }
        *lst = NULL;
    }
}