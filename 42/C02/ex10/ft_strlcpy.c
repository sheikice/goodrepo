#include <unistd.h>

unsigned int ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;	
	}
	return (i + 1);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;

	i = 0;
	while (i < size - 1 && i < ft_strlen(src) - 1)
	{
		dest[i] = src[i];
		i++;
	}	
	while(i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (ft_strlen(src));
}
#include <stdio.h>
int	main(int argc, char *argv[])
{
	char	res;
	if (argc != 3)
	{
		write(1, "Please, use good parameters : dest and src\n", 43);
		return (0);
	}
	printf("%s is copied to %s\n", argv[2], argv[1]);
	printf("The lenght of string src is %d and the result is: %s\n", ft_strlcpy(argv[1], argv[2], ft_strlen(argv[1])), argv[1]);
	return (0);
}
