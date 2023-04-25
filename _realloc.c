#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the previous allocated memory
 * @size: new size
 *
 * Return: pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int size)
{
	void *newptr = malloc(size);
	unsigned int i;

	if (!newptr)
		return (NULL);
	for (i = 0; i < size; i++)
		*((char *)newptr + i) = *((char *)ptr + i);
	free(ptr);
	return (newptr);
}
