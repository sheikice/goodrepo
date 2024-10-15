#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	ft_checkpara(char *base)
{
	int	i;
	int	j;

	i = 0;
	if(!base || ft_strlen(base) == 1)
		return (0);
	while(base[i])
	{
		j = i + 1;
		while(base[j])
		{
			if(base[i] == base[j])
				return (0);
			j++;
		}
		if(base[i] == ' ' || (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		i++;
	}
	return (1);
}

int	ft_indice_base(char str, char *base)
{
	int	i;

	i = 0;
	while(base[i])
	{
		if(base[i] == str)
			return (i);
		i++;
	}
	return (0);
}
int	ft_skip(char *str, char *base, int size_str)
{	
	int	i;
	int	sign;
	

	sign = 1;
	i = 0;
	while(str[i] == ' ')
		i++;
	while(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	if(size_str == 1 && str[i] == base[0])
		return (0);	
	if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	{	
		if(sign < 0 && str[i] != base[0])
			return (-1);
		return (1);
	}
	return(0);
}
int	ft_atoi_base(char *str, char *base)
{
	int	size_base;
	int	size_str;
	long int	res;
	int	i;
	int	sign;
	
	if(!ft_checkpara(base))
		return (0);
	i = 0;
	res = 0;
	size_base = ft_strlen(base);
	size_str = ft_strlen(str);
	sign = ft_skip(str, base, size_str);
	if(sign == 0)
		return (0);
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9' || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			res = res * size_base + ft_indice_base(str[i], base);
		}
		i++;
	}
	return (res * sign);
}

void	ft_putnbr(long int nbr)
{
	char	mod;
	
	if(nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	mod = nbr % 10 + 48;
	if(nbr > 9)
		ft_putnbr(nbr/10);
	write(1, &mod, 1);
}

int	main(int argc, char *argv[])
{
	if(argc != 3)
		return (1);

	ft_putnbr(ft_atoi_base(argv[1], argv[2]));
	write(1, "\n", 1);
	return (0);
}
