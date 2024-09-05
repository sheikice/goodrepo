#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

int	main(void)
{
	int	tab[4] = {0, 1, 2, 3};
	int	i;
	char	val;

	i = 0;
	ft_rev_int_tab(tab, 4);
	while (i < 4)
	{
		val = tab[i] + 48;
		write(1, &val, 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "/n", 1);
}
