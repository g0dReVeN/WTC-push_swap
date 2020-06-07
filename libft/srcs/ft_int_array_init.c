/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_array_init.c                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 14:43:15 by jordan_maco       #+#    #+#             */
/*   Updated: 2020/06/07 14:43:30 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_int_array_init(int *arr, int value, int size)
{
	int i;

	i = -1;
	while (++i < size)
		arr[i] = value;
}