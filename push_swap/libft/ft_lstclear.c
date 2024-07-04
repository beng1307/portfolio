#include "libft.h"

void    ft_lstclear(t_list **lst)
{
    t_list  *to_clear;

    if (lst)
    {
        to_clear = *lst;
        while (to_clear != NULL)
        {
            to_clear = to_clear->next;
            free(*lst);
            *lst = to_clear;
        }
    }
}