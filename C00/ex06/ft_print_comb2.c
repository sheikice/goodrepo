#include <unistd.h>

void	cheat(int i, int j)
{
	char	num1;
	char	num2;

	while (i < 98)
	{
		while (j < 99)
		{
			num1 = (i / 10) + 48;
			num2 = (i % 10) + 48;
			write (1, &num1, 1);
			write (1, &num2, 1);
			write (1, " ", 1);
			num1 = (j / 10) + 48;
			num2 = (j % 10) + 48;
			write (1, &num1, 1);
			write (1, &num2, 1);
			if (i < 97 || j < 98)
				write (1, ", ", 2);
			j++;
		}
		i++;
		j = i + 1;
	}
	write (1, "\n", 1);
}
void	ft_print_comb2(void)
{
	cheat(0,1);
}


int	main(void)
{
	ft_print_comb2();
	return (0);
}
