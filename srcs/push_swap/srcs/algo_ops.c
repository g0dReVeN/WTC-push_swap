/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:43:15 by jordan_maco       #+#    #+#             */
/*   Updated: 2018/08/29 20:36:05 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    get_minmax(t_stack a, int minmax[2])
{
	int i;

	i = -1;
	minmax[0] = a.stk[0];
	minmax[1] = minmax[0];
	while (++i < a.csize)
	{
		if (a.stk[i] < minmax[0])
			minmax[0] = a.stk[i];
		if (a.stk[i] > minmax[1])
			minmax[1] = a.stk[i];
	}
}

void    get_shiftdir(int size, int i, int *n)
{
	if (size % 2)
	{
		if (i <= (size / 2))
			*n = 0;
		else
			*n = 1;
	}
	else
	{
		if (i < (size / 2))
			*n = 0;
		else
			*n = 1;
	}
}

void    get_neighbours(t_stack a, int b, int c, int neighbours[2])
{
	int i;

	neighbours[1] = 0;
	if (b > a.stk[a.csize - 1] && b < a.stk[0])
		neighbours[0] = a.stk[0];
	else
	{
		i = 0;
		while (++i < a.csize)
		{
			if (b > a.stk[i - 1] && b < a.stk[i])
			{
				neighbours[0] = a.stk[i];
				get_shiftdir(a.csize, i, &neighbours[1]);
			}
			else if (c == a.stk[i])
				get_shiftdir(a.csize, i, &neighbours[1]);
		}
	}
}