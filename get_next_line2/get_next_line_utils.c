void *ft_realloc(void *ptr, size_t old_size, size_t new_size) 
{
    void *new_ptr;

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }

    if (ptr != NULL) {
        ft_memcpy(new_ptr, ptr, old_size);
        free(ptr);
    }

    return new_ptr;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		idx;

	idx = 0;
	if (dest == src || !n)
		return (dest);
	while (idx < n)
	{
		*((char *)dest + idx) = *((char *)src + idx);
		idx++;
	}
	return (dest);
}