/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:45:31 by rbatisti          #+#    #+#             */
/*   Updated: 2023/01/03 08:50:39 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_count(unsigned long n)
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

static char	*hex_str(unsigned int n, char *base)
{
	int		tam;
	char	*num;

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

int	print_hex(unsigned int n, char *base)
{
	int			len;
	char		*str;

	str = hex_str(n, base);
	len = ft_putstr(str);
	free(str);
	return (len);
}
