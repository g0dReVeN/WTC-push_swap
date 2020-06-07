/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ops.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:43:15 by jordan_maco       #+#    #+#             */
/*   Updated: 2018/08/29 20:36:05 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		recalibrate(t_stack a, int *value, int *pos, int size)
{
	int i;
	int j;
	int arrSize;

	i = -1;
	arrSize = 0;
	// int_array_init(-1, pos, size);
	while (++i < a.csize)
	{
		j = -1;
		while (++j < size)
			if (value[j] == a.stk[i])
				pos[arrSize++] = i;
	}

	return arrSize;
}

void	set_smallest_chunk(t_stack a, int *chunk, int size)
{
	int i;
	int temp[a.csize];

	i = -1;
	while (i++ < a.csize)
		temp[i] = a.stk[i];

	ft_int_array_sort(temp, a.csize);

	i = -1;
	while (i++ < size)
		chunk[i] = temp[a.csize - 1 - i];
}

int		get_position(t_stack a, int b)
{
	int i;

	i = -1;
	if (b > largest(a.stk, a.csize) || b < smallest(a.stk, a.csize))
		return get_index(a.stk, a.csize);
	else if (b > a.stk[a.csize - 1] && b < a.stk[0])
		return 0;
	else
		while (++i < a.csize - 1)
			if (a.stk[i] < b && a.stk[i + 1] > b)
				return i + 1;

	return i;
}

int		get_neighbours(t_stack a, int bMax)
{
	int i;
	int maxPos[2];

	i = 0;
	maxPos[1] = i;
	maxPos[0] = a.stk[i];
	while (++i < a.csize)
		if (a.stk[i] > maxPos[0])
		{
			maxPos[1] = i;
			maxPos[0] = a.stk[i];
		}

	i = -1;
	if (maxPos[0] < bMax || smallest(a.stk, a.csize) > bMax)
		return maxPos[1];
	else if ((a.stk[0] < bMax && a.stk[a.csize + i] > bMax) || a.csize + i == 0)
		return 0;
	else
		while (++i < a.csize - 1) 
			if (a.stk[i] > bMax && a.stk[i + 1] < bMax)
				return i + 1;

	return 0;
}

void	find_best_move(t_stack *a, t_stack *b, t_algo_ops *c, int *pos)
{
	int j;

	c->m2T[2][1] = pos[c->c[1]];
	c->m2T[2][0] = a->csize - c->m2T[2][1];
	c->m2T[3][1] = b->csize ? (get_neighbours(*b, a->stk[pos[c->c[1]]])) : 0;
	c->m2T[3][0] = b->csize ? (b->csize - c->m2T[3][1]) : 0;
	c->sOpts[1][0] = c->m2T[3][1] > c->m2T[2][1] ? c->m2T[3][1] : c->m2T[2][1];
	c->sOpts[1][1] = c->m2T[2][0] > c->m2T[3][0] ? c->m2T[2][0] : c->m2T[3][0];
	c->sOpts[1][2] = c->m2T[3][1] + c->m2T[2][0];
	c->sOpts[1][3] = c->m2T[2][1] + c->m2T[3][0];

	if ((j = smallest(c->sOpts[1], 4)) < c->c[3])
	{
		c->c[3] = j;
		j = -1;
		while (++j < 4)
		{
			if (j < 2)
			{
				c->m2T[0][j] = c->m2T[2][j];
				c->m2T[1][j] = c->m2T[3][j];
			}
			c->sOpts[0][j] = c->sOpts[1][j];
		}
	}
}