#include <unistd.h>
#include <stdio.h>

void	write_hexa(char c)
{
	int	i;
	char	hexa[16];
	
	i = 0;
	while (i < 10)
	{
		hexa[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		hexa[i] = 'a' + i - 10;
		i++;
	}
	if(c >= 16)
	{
		write_hexa(c / 16);
	}
		write(1, &hexa[c % 16], 1);

}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "//", 1);
			if(str[i] < 16)
				write(1, "0", 1);
			write_hexa(str[i]);
		}
		i++;
	}
	write(1,"\n", 1);
}

int	main(int argc, char *argv[])
{
	int i = 0;
	char str[1];
	if (argc != 2)
	{
		write(1, "Need a good parameter\n", 22);
		return (0);
	}
	ft_putstr_non_printable(argv[1]);
	return (0);
}
