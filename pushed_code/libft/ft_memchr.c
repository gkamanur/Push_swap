/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:20:54 by gkamanur          #+#    #+#             */
/*   Updated: 2024/11/21 14:26:47 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)s;
	unsigned char		target;
	size_t				i;

	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == target)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}
