#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int len;

	len = 0;
	while (*src++)
		len++;
	return (len);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if(min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if(*range == 0)
		return (-1);
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
