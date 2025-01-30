#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}
void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			ft_print_hex((unsigned char)str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
#include <stdio.h>
int	main()
{
	char	test_str[] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(test_str);
	printf("\n");
	return (0);
}
