#include <unistd.h>

int	ft_strlen(char *src)
{
	int len;

	len = 0;
	while (*src++)
		len++;
	return (len);
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
}

char	*ft_strdup(char *src)
{
	char *result;

	result = malloc(ft_strlen(src) + 1);
	ft_strcpy(result, src);

	return (result);
}
