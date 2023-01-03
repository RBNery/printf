/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:45:02 by rbatisti          #+#    #+#             */
/*   Updated: 2023/01/03 08:49:21 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_aux(const char *str, int i, va_list aux);

int	ft_printf(const char *str, ...)
{
	va_list	aux;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(aux, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			res += ft_printf_aux(str, i, aux);
			i++;
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	va_end(aux);
	return (res);
}

int	ft_printf_aux(const char *str, int i, va_list aux)
{
	if (str[i + 1] == '%')
		return (ft_putchar(str[i + 1]));
	else if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(aux, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(aux, char *)));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr(va_arg(aux, int)));
	else if (str[i + 1] == 'u')
		return (print_u(va_arg(aux, unsigned int)));
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
	{
		if (str[i + 1] == 'X')
			return (print_hex(va_arg(aux, unsigned int), "0123456789ABCDEF"));
		else
			return (print_hex(va_arg(aux, unsigned int), "0123456789abcdef"));
	}
	else if (str[i + 1] == 'p')
		return (ft_pointer(va_arg(aux, unsigned long long), \
			"0123456789abcdef"));
	else
		return (0);
}
