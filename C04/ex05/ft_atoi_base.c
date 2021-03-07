#include <unistd.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_iobase(char c, char *base)
{
	int cnt;

	cnt = 0;
	while (base[cnt] != '\0')
	{
		if (base[cnt] == c)
			return (cnt);
		cnt++;
	}
	return (-1);
}

int	ft_basechk(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if(base[i] == '-' || base[i] == '+' || base[i] == 0x9 || base[i] == 0xa ||
          		 base[i] == 0xb || base[i] == 0xc || base[i] == 0xd || base[i] == 0x20)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if(base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (ft_strlen(base));
}

int	ft_atoi_base(char *str, char *base)
{
	int int_data;
	int minus_cnt;

	if(ft_basechk(base) <= 1)
		return (0);
	int_data = 0;
	minus_cnt = 0;
	while (*str)
	{
		if(*str == '-' || *str == '+' || *str == 0x9 || *str == 0xa ||
           		*str == 0xb || *str == 0xc || *str == 0xd || *str == 0x20)
		{
			if(*str++ == '-')
				minus_cnt++;
		}
		else if(ft_iobase(*str, base) == -1)
			break ;
		else
		{
			int_data *= ft_strlen(base);
			int_data += ft_iobase(*str++, base);
		}
	}
	int_data = minus_cnt % 2 == 1 ? -(int_data) : int_data;
	return (int_data);
}
