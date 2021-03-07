#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *a, char *b)
{
	while (*a)
	{
		if(*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	if(*b != '\0')
		return (-(*b));
	return (0);
}

void	ft_sort(int size, char **arr)
{
	int i;
	int j;
	char *tmp;

	i = 1;
	while (i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			if(ft_strcmp(arr[i],arr[j]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;
	i = 1;
	ft_sort(argc, argv);
	while (i < argc)
	{
	ft_putstr(argv[i++]);
	write(1, "\n", 1);
	}
	return (0);
}
