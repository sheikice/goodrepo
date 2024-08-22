#include <unistd.h>

void	ft_putnbr(int n)
{
	char	mod;

	mod = n % 10;	
	if (n > 0)
	{
		ft_putnbr(n / 10);
	}
	write (1, &mod, 1);
}

void	ft_print_combn(int n)
{
	int	i;
	int	limit;
	int	temp;

	i = 1;
	limit = 0;
	while (i <= n)
	{
		limit = (limit * 10) + 9;
		i++;
	}
	i = 1;
	while (i <= limit)
	{
		temp = limit - i;
		while (temp > 9)
		{
			write(1, "0", 1);
			temp /= 10; 
		}
		ft_putnbr(i);
		if (i < limit - 1)
			write (1, ", ",1);
		i++;
	}
}

#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	ft_print_combn(atoi(argv[1]));
	write (1, "\n", 1);
	ft_putnbr(0);
	write (1, "\n", 1);
	ft_putnbr(1);
	return (0);
}
