#include <unistd.h>
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0)
	{
		if(*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int strlen;
	unsigned int to_find_len;
	int i;

	strlen = ft_strlen(str);
	to_find_len = ft_strlen(to_find);
	if(to_find_len == 0)
		return str;
	i = 0;
	while (i <= strlen - to_find_len)
	{
		if (*to_find == str[i])
			if (ft_strncmp(str + i, to_find, to_find_len) == 0)
				return (str + i);
		i++
	}
	return 0;
}
