/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_array_sort.c                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 14:43:15 by jordan_maco       #+#    #+#             */
/*   Updated: 2020/06/07 14:43:30 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_int_array_sort(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (++i <= size)
	{
		j = i + 1;
		while (--j && arr[j - 1] < arr[j])
			ft_swap(&arr[j], &arr[j - 1]);
	}
}