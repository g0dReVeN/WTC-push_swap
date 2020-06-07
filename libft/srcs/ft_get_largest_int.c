/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_largest_int.c                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 14:45:15 by jordan_maco       #+#    #+#             */
/*   Updated: 2020/06/07 14:45:30 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_get_largest_int(int *arr, int size)
{
	int max;
	int i;

	i = 0;
	max = arr[i];
	while (++i < size)
		if (arr[i] > max)
			max = arr[i];

	return max;
}