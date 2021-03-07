#include <stdlib.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ret);
}

int    ft_getlength(char **strs, char *sep, int size)
{
	int	len;
	int	i;
	int	j;
	int	k;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
		}
		k = 0;
		if(i < size - 1)
		{
			while (sep[k])
				k++;
		}
		len += j + k;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int	i;
	int	len;

	len = 0;
	if(size == 0)
	{
		string = malloc(sizeof(char));
		string = 0;
		return (0);
	}
	i = 0;
	string = malloc(ft_getlength(strs, sep, size) + 1);
	while (i < size)
	{
		ft_strcat(string, strs[i]);
		if(i == (size - 1))
			break ;
		ft_strcat(string, sep);
		i++;
	}
	return (string);
}
