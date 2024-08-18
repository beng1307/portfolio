#include "libft.h"

int ft_lstsize(t_list *lst)
{
    t_list  *counter;
    int     count;

    counter = lst;
    count = 0;
    while (counter != NULL)
    {
        count++;
        counter = counter->next;
    }
    return (count);
}