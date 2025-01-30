#include <unistd.h>
char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}
#include <stdio.h>
int	main()
{
	char	s[100];
	scanf("%99s", s);
	printf("%s\n", ft_strupcase(s));
	return (0);
}
