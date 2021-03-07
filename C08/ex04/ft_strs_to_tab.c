#include "ft_stock_str.h"
#include <stdlib.h>

int	getlen(char *src)
{
	int	len;

	len = 0;
	while (*src++)
		len++;
	return (len);
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

struct	s_stock_str	*ft_stock_strs_to_tab(int ac, char **av)
{
	int	idx;
	t_stock_str	*stock;

	idx = 0;
	if(!(stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	while ((av[idx] != 0) && idx < ac)
	{
		stock[idx].size = getlen(av[idx]);
		stock[idx].str = av[idx];
		if(!(stock[idx].copy = (char *)malloc((stock[idx].size + 1) * sizeof(char))))
			return (0);
		ft_strcpy(stock[idx].copy, av[idx]);
		idx++;
	}
	stock[idx].size = 0;
	stock[idx].str = 0;
	stock[idx].copy = 0;
	return (stock);
}
