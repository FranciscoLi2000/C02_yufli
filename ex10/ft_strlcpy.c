#include <unistd.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_size;
	unsigned int	i;

	src_size = 0;
	i = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_size);
}
#include <stdio.h>
int	main()
{
	char	dest[20];
	unsigned int	len;

	len = ft_strlcpy(dest, "Happy Chinese New Year!", sizeof(dest));
	printf("The copied string is %s, which has %u characters.\n", dest, len);
	return (0);
}
