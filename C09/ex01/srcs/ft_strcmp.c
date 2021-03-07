#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if(*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if(*s2 != '\0')
		return (-(*s2));
	return (0);
}
