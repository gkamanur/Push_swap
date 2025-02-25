/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:42:12 by gkamanur          #+#    #+#             */
/*   Updated: 2024/11/22 09:45:36 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*res;

	if (!dest && !src)
		return (0);
	res = dest;
	while (n--)
		*(char *)(res++) = *(char *)(src++);
	return (dest);
}
