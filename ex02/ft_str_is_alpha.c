#include <unistd.h>
int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] <= 91) || (str[i] >= 97 && str[i] <= 122))
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
	printf("%i\n", ft_str_is_alpha(s));
	return (0);
}
