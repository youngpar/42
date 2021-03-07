#include <unistd.h>

int	ft_sqrt(int nb)
{
	if(nb < 0)
		return (0);
	int idx;

	idx = 0;
	while (idx * idx <= nb)
	{
		if(idx * idx < nb)
			idx++;
		if(idx * idx == nb)
			return (idx);
	}
	return (0);
}
