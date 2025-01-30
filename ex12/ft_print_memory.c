#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_print_hex_digit(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c]);
}
// 打印地址（第一列）
void	print_address(unsigned long addr)
{
	int	i;
	char	*hex;
	char	addr_hex[16]; // 存储地址的十六进制形式
	int	leading_zero;

	hex = "0123456789abcdef";
	leading_zero = 1;
	// 将地址转换为十六进制字符
	i = 15;
	while (i >= 0)
	{
		addr_hex[i] = hex[addr & 0xF];
		addr = addr >> 4;
		i--;
	}
	// 打印地址，跳过前导零
	i = 0;
	while (i < 16)
	{
		if (addr_hex[i] != '0')
			leading_zero = 0;
		if (!leading_zero)
			ft_putchar(addr_hex[i]);
		i++;
	}
	ft_putchar(':');
	ft_putchar(' ');
}
// 打印十六进制内容（第二列）
void	print_hex_content(unsigned char *addr, unsigned int size, unsigned int line_start)
{
	unsigned int	i;

	i = 0;
	// 打印16个字符的十六进制值
	while (i < 16)
	{
		if (line_start + i < size)
		{
			ft_print_hex_digit(addr[i] / 16);
			ft_print_hex_digit(addr[i] % 16);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' '); // 每2个字符后添加空格
		i++;
	}
}
// 打印字符内容（第三列）
void	print_char_content(unsigned char *addr, unsigned int size, unsigned int line_start)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && (line_start + i) < size)
	{
		// 判断是否为可打印字符（ASCII 32-126）
		if (addr[i] >= 32 && addr[i] <= 126)
			ft_putchar(addr[i]);
		else
			ft_putchar('.'); // 不可打印字符用点代替
		i++;
	}
}
void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*p;

	if (size == 0)
		return ;
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		// 打印当前行的地址
		print_address((unsigned long)(addr + i));
		// 打印十六进制内容
		print_hex_content(p + i, size, i);
		// 打印字符内容
		print_char_content(p + i, size, i);
		ft_putchar('\n');
		i += 16; // 移动到下一行
	}
}
#include <stdio.h>
#include <string.h>
int	main()
{
	char	str[] = "Bonjour les amin ches...c. est fou.tout.ce qu on peut faire avec...print_memory...lol.lol...";

	ft_print_memory(str, strlen(str));
	return (0);
}
