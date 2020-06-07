/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:50:58 by jordan_maco       #+#    #+#             */
/*   Updated: 2018/08/29 20:35:52 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotate_left(t_stack *a, int i, int temp)
{
	while (++i < (a->csize - 1))
	{
		a->stk[i] = a->stk[i + 1];
	}
	a->stk[a->csize - 1] = temp;
}

void	rotate_right(t_stack *a, int i, int temp)
{
	while (--i > 0)
	{
		a->stk[i] = a->stk[i - 1];
	}
	a->stk[0] = temp;
}

void	rotate(t_stack *a, int direction)
{
	int i;
	int temp;

	if (a->csize > 1)
	{
		if (direction)
		{
			i = -1;
			temp = a->stk[0];
			rotate_left(a, i, temp);
		}
		else
		{
			i = a->csize;
			temp = a->stk[a->csize - 1];
			rotate_right(a, i, temp);
		}
	}
}

void	push(t_stack *a, t_stack *b)
{
	int pop;

	rotate(b, 1);
	pop = b->stk[b->csize - 1];
	b->csize--;

	a->csize++;
	rotate(a, 0);
	a->stk[0] = pop;
}

void	print_stk(t_stack a, t_stack b)
{
	int i;

	i = -1;
	while (++i < a.msize)
	{
		if (i < a.csize)
			ft_putnbr_fd(a.stk[i], 2);
		else
			ft_putchar_fd('-', 2);
		ft_putstr_fd("\t\t", 2);
		if (i < b.csize)
			ft_putnbr_fd(b.stk[i], 2);
		else
			ft_putchar_fd('-', 2);
		ft_putchar_fd('\n', 2);
	}
	ft_putstr_fd("=======\t\t=======\nStack A\t\tStack B\n", 2);
}