#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	i;
	int	tab[4] = {4, 1, 3, 2};
	char	val;

	i = 0;
	ft_sort_int_tab(tab, 4);
	while (i < 4)
	{
		val = tab[i] + 48;
		write(1, &val, 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
