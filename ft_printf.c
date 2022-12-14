/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:38:18 by rbatisti          #+#    #+#             */
/*   Updated: 2022/12/14 15:08:50 by rbatisti         ###   ########.fr       */
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

static int     pos_num(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int     num_len(int n)
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

char    *ft_itoa(int n)
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

int ft_printf(const char *str, ...)
{
	va_list temp;
	int i;
	int j;
	int tam;
	char *res;
	char c;
	int d;
		
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
				d = va_arg(temp, int);
				res = ft_itoa(d);
				while (res[j] != '\0')
                                {
                                        write(1, &res[j], 1);
                                        j++;
                                }
                                j = 0;
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
	int d = 23;
	ft_printf("rodolfo %s %c %d", bn, f, d);
	return (0);
}
