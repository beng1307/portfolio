#include "libft.h"

void	free_that(void **to_free)
{
	if (*to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
}