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
