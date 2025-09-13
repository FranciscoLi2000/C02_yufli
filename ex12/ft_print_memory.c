
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_puthex(byte_t byte)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";        
	// 输出高4位
	ft_putchar(hex_base[byte / 16]);
	// 输出低4位  
	ft_putchar(hex_base[byte % 16]);
}

/* 每个字节（8位）可以用两个十六进制数字表示
我们通过除以16得到高4位，通过取模16得到低4位，
然后用这些数值作为索引在十六进制字符表中查找对应的字符。*/

static void	print_in_ascii(char c)
{
	if (c >= 32 && c <= 126)
		ft_putchar(c);  // 直接输出字符，不是数字
	else
		ft_putchar('.');  // 不可打印字符用点号代替
}

static void	ft_putptr(void *ptr)
{
	unsigned long	addr;
	char			*hex_base;
	char			buffer[16];
	int				i;

	addr = (unsigned long)ptr;
	hex_base = "0123456789abcdef";
	i = 0;
	// 将地址转换为十六进制字符串
	while (addr > 0)
	{
		buffer[i++] = hex_base[addr % 16];
		addr /= 16;
	}
	// 反向输出（因为我们是从低位开始存储的）
	while (--i >= 0)
		ft_putchar(buffer[i]);
	ft_putchar(':');  // 地址后面通常跟一个冒号
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	byte_t	*ptr;
	unsigned int	i;
	unsigned int	j;

	ptr = (byte_t *)addr;
	i = 0;
	while (i < size)
	{
		// 输出当前行的起始地址
		ft_putptr(ptr + i);
		ft_putchar(' ');
		// 输出十六进制内容（每行最多16字节）
		j = 0;
		while (j < 16 && i + j < size)
		{
			ft_puthex(ptr[i + j]);
			ft_putchar(' ');
			j++;
		}
		// 如果这行不足16字节，用空格填充对齐
		while (j < 16)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			ft_putchar(' ');
			j++;
		}
		// 输出ASCII表示
		j = 0;
		while (j < 16 && i + j < size)
		{
			print_in_ascii(ptr[i + j]);
			j++;
		}
		ft_putchar('\n');
		i += 16;  // 移动到下一行
	}
	return (addr);
}
