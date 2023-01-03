/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatisti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:20:55 by rbatisti          #+#    #+#             */
/*   Updated: 2022/11/29 11:30:18 by rbatisti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countw(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) == c && *(s + i) != '\0')
			i++;
		if (*(s + i) != '\0')
		{
			count++;
			i++;
		}
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (*(s + i) && (*(s + i) != c))
	{
		count++;
		i++;
	}
	return (i);
}

static char	*ft_get(char const *s, char c, int start)
{
	char	*word;
	int		len;
	int		i;
	int		j;

	i = start;
	j = 0;
	len = ft_wordlen(s, c, start);
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (*(s + i) == c)
		i++;
	while (*(s + i) != c && *(s + i) != '\0')
	{
		word[j] = *(s + i);
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**ar;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ar = (char **)malloc((ft_countw(s, c) + 1) * sizeof(char *));
	if (!ar)
		return (NULL);
	while (*(s + i) != '\0')
	{
		while (*(s + i) == c && *(s + i) != '\0')
			i++;
		if (*(s + i) != '\0')
		{
			ar[j++] = ft_get(s, c, i++);
		}
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
	}
	ar[j] = NULL;
	return (ar);
}
