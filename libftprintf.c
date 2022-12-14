/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:38:18 by rbatisti          #+#    #+#             */
/*   Updated: 2022/12/14 14:06:05 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_printf(const char *str, ...)
{
	va_list temp;
	int i;
	int j;
	int tam;
	char *res;
	char c;
		
	//printf("%s \n", str);
	va_start(temp, str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
			{	
				res = va_arg(temp, char*);
				while (res[j] != '\0')
				{
					write(1, &res[j], 1);
					j++;
				}
				j = 0;
			}
			if (str[i] == 'c')
			{
				c = (char)va_arg(temp, int);
				write(1, &c, 1);
			}
			if (str[i] == 'd')
			{
				c = (char)va_arg(temp, int);
				write(1, &c, 1);
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}

}

int main()
{
	char bn[2] = "nf";
	char f = 'w';
	int d = 10;
	ft_printf("rodolfo %s %d %c", bn, f, d);
	return (0);
}
