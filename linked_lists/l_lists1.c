#include <stdio.h>
#include <stdlib.h>

struct list
{
	int				num;
	struct list 	*link;	
};

void	print_list(struct list *head)
{
	if (head == NULL)
		printf("Head is NULL");
	struct list *ptr = NULL;
	ptr = head;
	while (ptr != NULL)
	{	
		printf("%d ", ptr->num);
		ptr = ptr->link;
	}
}

// simple link list.
int	main(void)
{
	struct list *head;

	head = malloc(sizeof(struct list));
	head->num = 10;
	head->link = NULL;

	struct list *current = malloc(sizeof(struct list));
	
	current->num = 20;
	current->link = NULL;
	head->link = current;

	current = malloc(sizeof(struct list));
	current->num = 30;
	current->link = NULL;

	head->link->link = current;
	print_list(head);
}
