/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:41:43 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/09 08:56:56 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_power(double number, double exponent)
{
	double nbr;

	nbr = 1;
	while (exponent--)
		nbr *= number;
	return (nbr);
}
