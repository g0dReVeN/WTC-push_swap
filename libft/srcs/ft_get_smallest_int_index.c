/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_smallest_int_index.c                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 14:45:15 by jordan_maco       #+#    #+#             */
/*   Updated: 2020/06/07 14:45:30 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_get_smallest_int_index(int *arr, int size)
{
	int min;
	int index;
	int i;

	i = 0;
	index = i;
	min = arr[i];
	while (++i < size)
		if (arr[i] < min)
		{
			index = i;
			min = arr[i];
		}

	return index;
}