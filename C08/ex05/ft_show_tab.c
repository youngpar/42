#include "ft_stock_str.h"
#include <unistd.h>

int	ft_getlen(char *src)
{
	int	len;

	len = 0;
	while (*src++)
		len++;
	return (len);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_getlen(str));
	write(1, "\n", 1);
}

void	ft_putnbr(int size)
{
	if(size >= 10)
		ft_putnbr(size / 10);
	ft_putchar((size % 10) + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;

	idx = 0;
	while (par[idx].size)
	{
		ft_putnbr(par[idx].size);
		ft_putchar('\n');
		ft_putstr(par[idx].str);
		ft_putstr(par[idx].copy);
		idx++;
	}
}
