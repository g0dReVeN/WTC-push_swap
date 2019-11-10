/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:04:03 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/15 10:18:25 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long int	ft_atoll(const char *str)
{
	int						sign;
	int						scount;
	unsigned long long int	num;

	sign = 1;
	scount = 0;
	num = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (++scount > 1)
			return (0);
		(*(str++) == '-') && (sign = -1);
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *(str++) - '0';
	return ((num > 9223372036854775807) ? 0 : (num * sign));
}
