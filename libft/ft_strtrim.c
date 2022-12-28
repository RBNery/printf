/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:23:43 by rbatisti          #+#    #+#             */
/*   Updated: 2022/11/15 15:15:59 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	i = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[i]) && i != 0)
		i--;
	return (ft_substr(s1, 0, i + 1));
}

/*
#include <stdio.h>

int	main()
{
	char	*s1 = "";
	char	*set = " \n\t";
	printf("%s\n", ft_strtrim(s1, set));
	printf("s1: %s	|	size: %d	|	set: %s\n \
	Result: %s	|	Size: %d\n", s1, ft_strlen(s1), set, \
	ft_strtrim(s1, set), ft_strlen(ft_strtrim(s1, set)));
}
*/