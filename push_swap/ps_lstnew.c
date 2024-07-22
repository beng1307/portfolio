#include "push_swap.h"

static void	del_stacks(t_list **stk_a, t_list **stk_b)
{
	t_list  *to_clear;

    if (stk_a)
    {
        to_clear = *stk_a;
        while (to_clear)
        {
            to_clear = to_clear->next;
            free(*stk_a);
            *stk_a = to_clear;
        }
		*stk_a = NULL;
    }
    if (stk_b)
    {
        to_clear = *stk_b;
        while (to_clear)
        {
            to_clear = to_clear->next;
            free(*stk_b);
            *stk_b = to_clear;
        }
		*stk_b = NULL;
    }
}

t_list *ps_lstnew(int content, t_list **stk_a, t_list **stk_b)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
	{
		del_stacks(stk_a, stk_b);
		exit(-1);
	}
    new_node->content = content;	
    new_node->next = NULL;
    return (new_node);
}

t_list *ps_create_new(int content, t_list **list)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
	{
		ft_lstclear(list);
		exit (-1);
	}
    new_node->content = content;	
    new_node->next = NULL;
    return (new_node);
}

t_list *newlst(int content, t_list **list, char **spl_arg)
{
    t_list *new_node;
    
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		ft_lstclear(list);
		free_that(spl_arg);
		exit (-1);
	}
    new_node->content = content;	
    new_node->next = NULL;
    return (new_node);
}