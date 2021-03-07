#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_numprint(int *num, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		ft_putchar(num[idx] + '0');
		idx++;
	}
	if(num[0] != 10 - n)
		write(1, ", ", 2);
}

void		ft_inc(int *num, int n)
{
	int	idx;
	int	idx_max;

	idx = n - 1;
	idx_max = 9;

	while (num[idx] == idx_max)
	{
		idx--;
		idx_max--;
	}
	num[idx]++;
	while (idx < n)
	{
		num[idx + 1] = num[idx] + 1;
		idx++;
	}
}

void		ft_pirnt_combn(int n)
{
	int	idx;
	int	num[10];

	idx = -1;
	while (++idx < n)
	{
		num[idx] = idx;
	}
	while (num[0] <= (10 - n))
	{
		ft_numprint(num, n);
		if (num[n - 1] <  9)
			num[n - 1]++;
		else
			ft_inc(num, n);
	}
}
