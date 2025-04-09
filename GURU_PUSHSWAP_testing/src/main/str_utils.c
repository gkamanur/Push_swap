/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:50:55 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/09 15:44:28 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/pushswap.h"

void	putstr_fd(char *str, int fd)
{
	fflush(fd);
	while (*str)
		write(fd, str++, 1);
}

void	putstr_clr(char *str, int fd, char *clr)
{
	putstr_fd(clr, fd);
	putstr_fd(str, fd);
	putstr_fd(RESET "\n", fd);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	return(0);
}

long int	ft_atoi(const char *str)
{
	long int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str && (check(*str) == 1))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (check(*str) == 2))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
