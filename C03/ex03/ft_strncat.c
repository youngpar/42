#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (nb > 0)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (ret);
}
