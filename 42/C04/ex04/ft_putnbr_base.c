#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while(base[i])
		i++;
	return (i);	
}

int	ft_check_base(char *base, int nb_base)
{
	int	i;
	int	j;
	char	temp;

	i = 0;
	while(i <= nb_base)
	{
		temp = base[i];
		j = i + 1;
		if(base[i] == '-' || base[i] == '+')
			return (0);
		while(j <= nb_base)
		{
			if(base[j] == temp)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	nb_base;
	int	mod;

	nb_base = ft_strlen(base);
	if(nb_base < 2 || !base || !ft_check_base(base, nb_base))
		return;
	if(nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1; 
	}
		mod = nbr % nb_base;
	if (nbr >= nb_base)
	{
		ft_putnbr_base(nbr/nb_base, base);
	}
		write(1, &base[mod], 1);
}

int	main(int argc, char *argv[])
{
	if(argc != 3)
		return (0);
	ft_putnbr_base(atoi(argv[1]), argv[2]);
	write(1, "\n", 1);
	return (0);
}
