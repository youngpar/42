#include <unistd.h>

int	ft_strlen(char *src)
{
	int len;

	len = 0;
	while (*src++)
		len++;
	return (len);
}

int	*ft_range(int min, int max)
{
	int	*nptr;
	int	i;
	int	*parr;

	nptr = 0;
	i = 0;
	if(min >= max)
		return (nptr);
	parr = malloc((max - min) * sizeof(int));
	while (i < max - min)
	{
		parr[i] = min + i;
		i++;
	}
	return (parr);
}
