#include <unistd.h>

int	ft_isspace(int c)
{
	if(c == 0x9)
		return 0x9;
	if(c == 0xa)
		return 0xa;
	if(c == 0xb)
		return 0xb;
	if(c == 0xc)
		return 0xc;
	if(c == 0xd)
		return 0xd;
	if(c == 0x20)
		return 0x20;
	return 0;
}

void	is_negative(char c, int *minus_cnt)
{
	if(c == '-')
		*minus_cnt = *minus_cnt + 1;
}

int	ft_atoi(char *str)
{
	int int_data;
	int minus_cnt;

	int_data = 0;
	minus_cnt = 0;
	while (*str)
	{
		if(ft_isspace(*str) == 0)
		{
			if(*str == '-' || *str == '+')
				is_negative(*str, &minus_cnt);
			else if(*str >= '0' && *str <= '9')
				int_data = 10 * int_data + ((*str) - '0');
			else
				break;
		}
		str++;
	}
	if(minus_cnt % 2 == 1)
		int_data = -(int_data);
	return int_data;
}
