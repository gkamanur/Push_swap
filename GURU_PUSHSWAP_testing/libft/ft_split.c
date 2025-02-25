/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:38:11 by gkamanur          #+#    #+#             */
/*   Updated: 2024/11/25 10:46:09 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && (*s == c))
			++s;
		if (*s && (*s != c))
		{
			++count;
			while (*s && (*s != c))
				++s;
		}
	}
	return (count);
}

void	ft_free_split(char **res, size_t i)
{
	if (!res)
		return ;
	while (i > 0)
		free(res[--i]);
	free(res);
}

char	*res_word(const char *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && (s[len] != c))
		++len;
	word = ft_substr(s, 0, len);
	if (!word)
		return (NULL);
	return (word);
}

char	**alloc_word(const char *s, char c, char **res)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			++s;
		if (*s && (*s != c))
		{
			res[i] = res_word(s, c);
			if (!res[i])
			{
				ft_free_split(res, i);
				return (NULL);
			}
			s += ft_strlen(res[i]);
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((ft_word(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!alloc_word(s, c, result))
		return (NULL);
	return (result);
}
