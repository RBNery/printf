/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:12:07 by rbatisti          #+#    #+#             */
/*   Updated: 2022/11/15 14:12:08 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
