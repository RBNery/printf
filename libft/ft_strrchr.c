/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:43:23 by rbatisti          #+#    #+#             */
/*   Updated: 2022/11/15 14:36:28 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*res;

	i = ft_strlen(s);
	res = &s[i];
	while (i >= 0)
	{
		if (*res == c)
			return ((char *)res);
		res--;
		i--;
	}
	if (c == '\0')
		return ((char *)res);
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
    // Storing it in string array
    char string[] = "Geeks for Geeks";
  
    // The character we've to search for
    char character = 'k';
  
    // Storing in a pointer ptr
    char* ptr = strrchr(string, character);
    printf("%c\n", *ptr);
    ptr = ft_strrchr(string, character);
    printf("%c\n", *ptr);
    return 0;
}*/
