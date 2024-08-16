#include "libft.h"

void	free_that(char **to_free)
{
	if (*to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
}