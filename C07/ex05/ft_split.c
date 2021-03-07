#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int	ft_issep(char chars, char *charset)
{
	while (*charset)
	{
		if(*charset == chars)
			return (1);
		charset++;
	}
	if(chars == '\0')
		return (1);
	return (0);
}

void	checkcpy(char *dst, char *src, char *charset)
{
	int 	i;

	i = 0;
	while (ft_issep(src[i], charset) == 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	cnt_sep(char *str, char *charset)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (str[idx])
	{
		if(ft_issep(str[idx], charset) == 0 && ft_issep(str[idx + 1], charset) == 1)
			cnt++;
		idx++;
	}
	return (cnt);
}

void	ft_sep(char **result, char *str, char *charset)
{
	int	idx;
	int	size;
	int	cur;

	idx = 0;
	cur = 0;
	while (str[idx])
	{
		if(ft_issep(str[idx], charset) == 1)
			idx ++;
		else
		{
			size = 0;
			while (ft_issep(str[idx + size], charset) == 0)
				size++;
			result[cur] = (char *)malloc(sizeof(char) * (size + 1));
			checkcpy(result[cur], &str[idx], charset);
			idx += size;
			cur++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int	sepnum;
	char	**result;

	if(*str == '\0')
		return (0);
	sepnum = cnt_sep(str, charset);
	result = (char **)malloc(sizeof(char *) * (sepnum + 1));
	result[sepnum] = 0;
	ft_sep(result, str, charset);
	return (result);
}
