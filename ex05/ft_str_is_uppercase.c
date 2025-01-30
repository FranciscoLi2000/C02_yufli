#include <unistd.h>
int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 64 && str[i] <= 90)
			return (1);
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main()
{
	char	s[100];
	scanf("%99s", s);
	printf("%i\n", ft_str_is_uppercase(s));
	return (0);
}
