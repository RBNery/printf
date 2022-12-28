/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:31:02 by rbatisti          #+#    #+#             */
/*   Updated: 2022/11/15 14:39:36 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int a)
{
	if (a >= 65 && a <= 90)
		a += 32;
	return (a);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	char	a = '1';
	char	b;

	b = tolower(a);
	a = ft_tolower(a);
	printf("%c\n%c", a, b);
	return (0);
}*/
