#include <unistd.h>

int	ft_is_prime(int nb)
{
	if(nb < 2)
		return (0);
	int div;

	div = 2;
	while (div <= nb / 2)
	{
		if(nb % div == 0)
			return (0);
		div++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if(ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
}
