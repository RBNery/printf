#include "libft.h"

static int     pos_num(unsigned int n)
{	
	if (n < 0)
		return (-n);
	return (n);
}
 
static int     num_len(unsigned int n)
{
	int	len;
	
	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}
 
char    *ft_utoa(unsigned int n)
{
	char	*res;
	int	len;
 
	len = num_len(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	res[0] = '-';
	else if (n == 0)
	res[0] = '0';
	while (n != 0)
	{
		--len;
		res[len] = pos_num(n % 10) + '0';
		n = n / 10;
	}
	return (res);
}