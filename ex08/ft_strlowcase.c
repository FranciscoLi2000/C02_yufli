#include <unistd.h>
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 64 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}
#include <stdio.h>
int	main()
{
	char	s[100];
	scanf("%99s", s);
	printf("%s\n", ft_strlowcase(s));
	return (0);
}
