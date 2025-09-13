
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = ft_strlen(src);
	if (size > src_len)
	{
		i = 0;
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (src_len);
}
