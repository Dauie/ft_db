#include "ft_db.h"

void	*db_memalloc(size_t size)
{
	void	*memory;

	if (!(memory = (void *)malloc(size)))
	memset(memory, 0, size);
	return (memory);
}
