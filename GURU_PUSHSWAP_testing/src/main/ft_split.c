/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:16:46 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:42:13 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/pushswap.h"

int	ft_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

int	ft_wordlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

void	free_split(char **result)
{
	int i = 0;
	if (!result)
		return ;
	while (result[i])
		free(result[i++]);
	free(result);
	return ;
}

char	*ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && (i < (n - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**result;

	result = (char **)malloc((ft_word(s, c) + 1) * sizeof(char *));
	if (!s || !c || !result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			result[i] = (char *)malloc((ft_wordlen(s, c) + 1) * sizeof(char));
			if (!result[i])
				free_split(result);
			ft_strlcpy(result[i++], s,ft_wordlen(s, c) + 1);
			s +=ft_wordlen(s, c);
		}
	}
	result[i] = NULL;
	return (result);
}
