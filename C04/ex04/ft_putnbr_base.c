#include <unistd.h>
int	ft_strlen(char *base)
{
	int len;

	len = 0;
	while (*base++)
	{
		len++;
		if(*base == '-' || *base == '+')
		{
			len = -1;
			break ;
		}
	}
	return (len);
}

int	ft_isredup(char *base)
{
	int stat;
	int length;
	int i;
	int j;

	stat = 1;
	i = 0;
	length = ft_strlen(base);
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if(base[i] == base[j])
				stat = 0;
			j++;
		}
		i++;
	}
	return stat;
}

void	int_tok(int nbr, int base_num, char *base)
{
	char data;

	if(nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_num)
		int_tok(nbr / base_num, base_num, base);
	data = base[nbr % base_num];
	write(1, &data, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_num;

	if(ft_strlen(base) <= 1)
		return ;
	if(ft_isredup(base))
		base_num = ft_strlen(base);
	else
		return ;
	int_tok(nbr, base_num, base);
}
