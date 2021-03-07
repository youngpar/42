#include <unistd.h>

unsigned int    ft_strlen(char *str)
{
    unsigned int len;
    
    len = 0;
    while (*str++)
        len++;
    return (len);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len;
	unsigned int i;

	i = 0;
	dest_len = ft_strlen(dest);
	if(size <= dest_len)
		return size + dest_len - 1;
	while (*dest)
		dest++;
	while (i < size - dest_len -  1)
	{
		if(src[i] == '\0')
			break ;
		*dest = src[i];
		dest++;
		i++;
	}
	*dest = '\0';
	return (dest_len + ft_strlen(src));
}
