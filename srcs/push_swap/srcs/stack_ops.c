/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:50:58 by jordan_maco       #+#    #+#             */
/*   Updated: 2018/09/01 14:04:48 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both_left(t_stack *a, t_stack *b, t_ops *cnode)
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
	if (b->csize > 1)
	{
		i = -1;
		temp = b->stk[0];
		while (++i < (b->csize - 1))
		{
			b->stk[i] = b->stk[i + 1];
		}
		b->stk[b->csize - 1] = temp;
	}

	add_inst(cnode, "rr");
}

void	rotate_both_right(t_stack *a, t_stack *b, t_ops *cnode)
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
	if (b->csize > 1)
	{
		i = b->csize;
		temp = b->stk[b->csize - 1];
		while (--i > 0)
		{
			b->stk[i] = b->stk[i - 1];
		}
		b->stk[0] = temp;
	}

	add_inst(cnode, "rrr");
}

void	rotate_left(t_stack *a, t_ops *cnode, int s)
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
	else
		s = 2;

	if (s == 0)
		add_inst(cnode, "ra");
	else if (s == 1)
		add_inst(cnode, "rb");
}

void	rotate_right(t_stack *a, t_ops *cnode, int s)
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
	else
		s = 2;

	if (s == 0)
		add_inst(cnode, "rra");
	else if (s == 1)
		add_inst(cnode, "rrb");
}

void	push(t_stack *a, t_stack *b, t_ops *cnode, int s)
{
	int pop;

	rotate_left(b, cnode, 2);
	pop = b->stk[b->csize - 1];
	b->csize--;

	a->csize++;
	rotate_right(a, cnode, 2);
	a->stk[0] = pop;

	if (s == 0)
		add_inst(cnode, "pa");
	else if (s == 1)
		add_inst(cnode, "pb");
}