/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:16:45 by gkamanur          #+#    #+#             */
/*   Updated: 2024/11/22 11:42:43 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search_str)
{
	char	*res;

	res = 0;
	while (*str != '\0')
	{
		if (*str == (unsigned char)search_str)
			res = (char *)str;
		++str;
	}
	if (!(unsigned char)search_str)
		return ((char *)str);
	return (res);
}
