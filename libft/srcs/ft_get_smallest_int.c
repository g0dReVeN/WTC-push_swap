/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_smallest_int.c                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 14:45:15 by jordan_maco       #+#    #+#             */
/*   Updated: 2020/06/07 14:45:30 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_get_smallest_int(int *arr, int size)
{
	int min;
	int i;

	i = 0;
	min = arr[i];
	while (++i < size)
		if (arr[i] < min)
			min = arr[i];

	return min;
}