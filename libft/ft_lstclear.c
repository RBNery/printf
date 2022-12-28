/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:17:07 by rbatisti          #+#    #+#             */
/*   Updated: 2022/11/15 14:17:09 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (!(*lst))
		return ;
	while (*lst)
	{
		p = (**lst).next;
		ft_lstdelone(*lst, del);
		*lst = p;
	}
	*lst = 0;
}
