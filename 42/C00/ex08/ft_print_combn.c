#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int i)
{
	char	mod;

	mod = (i % 10) + 48;	
	if (i > 9)
		ft_putnbr(i / 10);
	write (1, &mod, 1);
}

void	print_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(tab[i]);
		i++;
	}
}

void	ft_inc_tab(int *tab, int index, int n)
{
	if ((tab[index] + 1) == tab[index + 1])
	{
		ft_inc_tab(tab, index - 1, n);
		tab[index] = tab[index - 1];
	}
		tab[index]++;
}

void	ft_print_combn(int n)
{
	int	*tab;
	int	i;

	tab = NULL;
	tab = malloc (sizeof(int) * (n + 1));
	if (!tab)
		return;
	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	tab[i] = 10;
	print_tab(tab, n);
	while (tab[0] < 10 - n)
	{
		write(1, ", ", 2);
		ft_inc_tab(tab,  n - 1, n);
		print_tab(tab, n);
	}
	write(1, "\n", 1);
	free(tab);	
}

int	main(int argc, char *argv[])
{
	if (argc != 2 || atoi(argv[1]) < 1 || atoi(argv[1]) > 9)
	{	
		write(1, "Not a good parameter\n", 21);
		return (0);
	}
	ft_print_combn(atoi(argv[1]));
	return (0);
}
