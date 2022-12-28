/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:22:15 by rbatisti          #+#    #+#             */
/*   Updated: 2022/11/15 14:22:17 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	res;

	a = 0;
	b = 0;
	if (size == 0 || size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
		res = ft_strlen(src) + ft_strlen(dst);
	while (dst[b])
		b++;
	while (b + 1 < size && src[a])
	{
		dst[b] = src[a];
		a++;
		b++;
	}
	dst[b] = '\0';
	return (res);
}	
