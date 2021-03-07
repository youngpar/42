#include <unistd.h>

int	ft_fibonacci(int index)
{
	if(index < 0)
		return (-1);
	if(index == 0 || index == 1)
		return (index);
	return ft_fibonacci(n - 1) + ft_fibonacci(n - 2);
}
