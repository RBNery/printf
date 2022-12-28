/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:04:04 by rbatisti          #+#    #+#             */
/*   Updated: 2022/11/15 14:04:05 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	tam;
	void	*res;

	tam = size * num;
	res = malloc(tam);
	if (!res)
		return (0);
	ft_memset(res, 0, tam);
	return (res);
}
