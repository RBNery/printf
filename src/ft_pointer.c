#include "../include/ft_printf.h"

static int	ft_count(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*hex_str(unsigned long long n, char *base)
{
	int	tam;
	char *num;

	tam = ft_count(n);
	num = (char *)malloc(sizeof(char) * (tam + 1));
	if (!num)
		return (NULL);
	num[tam] = '\0';
	while (tam > 0)
	{
		num[tam - 1] = base[n % 16];
		n = n / 16;
		tam--;
	}
	return (num);
	
}

int	ft_pointer(unsigned long long n, char *base)
{
	int			len;
	char		*str;
	
	len = 0;
	if (n == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += ft_putstr("0x"); 
		str = hex_str(n, base);
		len += ft_putstr(str);
		free(str);
	}
	return (len);
}
