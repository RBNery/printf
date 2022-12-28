/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:41:46 by rbatisti          #+#    #+#             */
/*   Updated: 2022/11/15 14:39:04 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int a)
{
	if (a >= 97 && a <= 122)
		a -= 32;
	return (a);
}

/*
#include <stdio.h>
#include <ctype.h>

int     main()
{
        char    a = 'a';
        char    b;

        b = toupper(a);
        a = ft_toupper(a);
        printf("%c\n%c", a, b);
        return (0);
}*/
