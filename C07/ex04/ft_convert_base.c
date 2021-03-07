#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
extern	int	ft_strlen(char *str);
extern	char	*int_tok(int value, char *base_to);

int		ft_fbase(char c, char *base)
{
	int	value;

	value = 0;
	while (base[value] != '\0')
	{
		if(base[value] == c)
			return (value);
		value++;
	}
	return (-1);
}

int		ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_strlen(base) - 1)
	{
		if(base[i] == '+' || base[i] == '-' || base[i] == ' ' ||
				base[i] == '\n' || base[i] == '\r' || base[i] == '\v' ||
				base[i] == '\t' || base[i] == '\f')
			return (0);
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (ft_strlen(base));
}

int		convert_to_int(char *nbr, char *base_from)
{
	int	result;
	int	minus_cnt;

	minus_cnt = 0;
	result = 0;
	while (*nbr)
	{
		if(*nbr == ' ' || *nbr == '+' || *nbr == '-' || *nbr == '\r' ||
				*nbr == '\t' || *nbr == '\v' || *nbr == '\f' || *nbr == '\n')
		{
			if(*nbr == '-')
				minus_cnt++;
		}
		else if(ft_fbase(*nbr, base_from) == -1)
			break ;
		else
		{
			result *= ft_strlen(base_from);
			result += ft_fbase(*nbr, base_from);
		}
		nbr++;
	}
	result = minus_cnt % 2 == 1 ? -(result) : result ;
	return (result);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	value;
	char	*value_point;

	if(ft_check_base(base_from) < 2)
		return (0);
	if(ft_check_base(base_to) < 2)
		return (0);
	value = convert_to_int(nbr, base_from);
	value_point = int_tok(value, base_to);
	return (value_point);
}
