#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	int_tok(int nb)
{
	if (nb >= 10)
		int_tok(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648" , 11);
		return ;
	}
	else if (nb > 2147483647 || nb < -2147483648)
		return ;
	else if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	int_tok(nb);
}
