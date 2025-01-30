#include <unistd.h>
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
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
	printf("%i\n", ft_str_is_numeric(s));
	return (0);
}
