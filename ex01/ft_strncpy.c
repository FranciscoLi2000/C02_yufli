#include <unistd.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && src[i] != '\0')
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
	char	src[100];
	int	n;

	scanf("%u", &n);
	scanf("%99s", src);
	printf("%s\n", ft_strncpy(dest, src, n));
	return (0);
}
