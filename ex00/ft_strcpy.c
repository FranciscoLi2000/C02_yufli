#include <unistd.h>
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
#include <stdio.h>
int	main()
{
	char	dest[100];
	char	*src;

	src = "We are the Champions!";
	printf("%s\n", ft_strcpy(dest, src));
	return (0);
}
