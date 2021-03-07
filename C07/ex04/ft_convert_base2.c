#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
extern	int	ft_check_base(char *base);
extern	int	ft_fbase(char c, char *base);

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while(*str++)
		len++;
	return (len);
}

void		puttoarr(char *result, char c)
{
	while (*result)
		result++;
	*result = c;
}

int		get_numlen(int value, int base_num)
{
	int	ret;

	ret = 0;
	if(value < 0)
		ret++;
	while (value != 0)
	{
		value /= base_num;
		ret++;
	}
	return (ret);
}

char		*int_tok(int value, char *base_to)
{
	int	numlen;
	char	*result;

	numlen = get_numlen(value, ft_strlen(base_to));
	result = (char *)malloc(sizeof(char) * (numlen + 1));
	if(value < 0)
	{
		result[0] = '-';
		value = -(value);
	}
	while (value != 0)
	{
		result[numlen - 1] = base_to[value % ft_strlen(base_to)];
		value /= ft_strlen(base_to);
		numlen--;
	}
	return (result);
}
