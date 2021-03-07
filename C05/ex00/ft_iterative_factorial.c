#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	if(nb < 0)
		return 0;
	if(nb == 0)
		return 1;
	int result;

	result = 1;
	while (nb > 0)
	{
		result *= nb--;
	}
	return (result);
}
