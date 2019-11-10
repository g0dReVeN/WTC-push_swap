/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:50:58 by jordan_maco       #+#    #+#             */
/*   Updated: 2018/08/29 20:36:18 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    shift_left(t_stack *a, t_ops *cnode, int s)
{
	int i;
	int temp;

	if (a->csize > 1)
	{
		i = -1;
		temp = a->stk[0];
		while (++i < (a->csize - 1))
		{
			a->stk[i] = a->stk[i + 1];
		}
		a->stk[a->csize - 1] = temp;
	}
	if (s == 0)
		add_inst(cnode, "ra");
	else if (s == 1)
		add_inst(cnode, "rb");
}

void    shift_right(t_stack *a, t_ops *cnode, int s)
{
	int i;
	int temp;

	if (a->csize > 1)
	{
		i = a->csize;
		temp = a->stk[a->csize - 1];
		while (--i > 0)
		{
			a->stk[i] = a->stk[i - 1];
		}
		a->stk[0] = temp;
	}
	if (s == 0)
		add_inst(cnode, "rra");
	else if (s == 1)
		add_inst(cnode, "rrb");
}

void    push(t_stack *a, int b, t_ops *cnode, int s)
{
	a->csize = a->csize + 1;
	shift_right(a, cnode, 2);
	a->stk[0] = b;
	if (s == 0)
		add_inst(cnode, "pa");
	else if (s == 1)
		add_inst(cnode, "pb");
}

int     pop(t_stack *a, t_ops *cnode, int s)
{
	int ret;

	shift_left(a, cnode, s);
	ret = a->stk[a->csize - 1];
	a->csize = a->csize - 1;
	return (ret);
}

void    print_stk(t_stack a, t_stack b)
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