#include <unistd.h>
int	is_new_word(char prev_char)
{
	return (!((prev_char >= 'a' && prev_char <= 'z')
		|| (prev_char >= 'A' && prev_char <= 'Z')
		|| (prev_char >= '0' && prev_char <= '9')));
}
char	*ft_strcapitalize(char *str)
{
	int	i;
	char	prev_char;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_new_word(prev_char) && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (is_new_word(prev_char) && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		prev_char = str[i];
		i++;
	}
	return (str);
}
#include <stdio.h>
int	main()
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(str));
	return (0);
}
