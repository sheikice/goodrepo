#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_putnbr(unsigned int nbr)
{
	char	mod;

	mod = nbr % 10 + 48;
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &mod, 1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	relative_size;
	unsigned int	i;
	
	relative_size = size - ft_strlen(dest) - 1;
	i = 0;
	while ( (i < relative_size) && src)
	{
		dest[i - relative_size + size - 1] = src[i];
		i++;
	}
	while ( i  < size)
	{
		dest[i - relative_size + size - 1] = '\0';
		i++;
	}
	return (ft_strlen(dest));
}

int	main(int argc, char *argv[])
{
	unsigned int	size;
	unsigned int	new_size;
	unsigned int		i;
	char		*dest;
	
	if (argc != 3)
	{
		write(1, "Use this format: ./a.out dest src\n dest must not contain more than 9 characters\n", 79);
		return (0);
	}
	dest = malloc(10 * sizeof(char));
	if(!dest)
		return (1);
	i = 0;
	while(argv[1][i] && i < 10)
	{
		dest[i] = argv[1][i];
		i++;
	}
	write(1, "\n", 1);
	while( i < 10)
	{
		dest[i] = '\0';
		i++;
	}
	i = 0;
	size = 10;
	new_size = ft_strlcat(dest, argv[2], size);
	argv[1] = dest;
	while (argv[1][i])
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(dest);
	ft_putnbr(new_size);
	write(1, "\n", 1);
	return (0);
}
