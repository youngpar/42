#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int result;

	result = 1;
	if(nb == 0 && power == 0)
		return (1);
	if(nb < 0)
		return (0);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
