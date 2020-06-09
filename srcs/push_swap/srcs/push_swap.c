/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:50:39 by jordan_maco       #+#    #+#             */
/*   Updated: 2018/09/01 16:03:31 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rot1(t_stack *a, t_stack *b, t_ops *head, int c, int m2TA[], int m2TB[])
{
	if (m2TB[1] < m2TA[1])
	{
		c = m2TB[1];
		while (c--)
			rotate_both_left(a, b, head);
		c = m2TA[1] - m2TB[1];
		while (c--)
			rotate_left(a, head, 0);
	}
	else
	{
		c = m2TA[1];
		while (c--)
			rotate_both_left(a, b, head);
		c = m2TB[1] - m2TA[1];
		while (c--)
			rotate_left(b, head, 1);
	}
}

void	rot2(t_stack *a, t_stack *b, t_ops *head, int c, int m2TA[], int m2TB[])
{
	if (m2TB[0] < m2TA[0])
	{
		c = m2TB[0];
		while (c--)
			rotate_both_right(a, b, head);
		c = m2TA[0] - m2TB[0];
		while (c--)
			rotate_right(a, head, 0);
	}
	else
	{
		c = m2TA[0];
		while (c--)
			rotate_both_right(a, b, head);
		c = m2TB[0] - m2TA[0];
		while (c--)
			rotate_right(b, head, 1);
	}
}

void	rot(t_stack *a, t_stack *b, t_ops *head, int c, int m2TA[], int m2TB[])
{
	switch (c)
	{
	case 0:
		rot1(a, b, head, c, m2TA, m2TB);
		break;
	case 1:
		rot2(a, b, head, c, m2TA, m2TB);
		break;
	case 2:
		c = m2TB[1];
		while (c--)
			rotate_left(b, head, 1);
		c = m2TA[0];
		while (c--)
			rotate_right(a, head, 0);
		break;
	case 3:
		c = m2TA[1];
		while (c--)
			rotate_left(a, head, 0);
		c = m2TB[0];
		while (c--)
			rotate_right(b, head, 1);
		break;
	}
}

void	exec_ops(t_stack *a, t_stack *b, t_algo_ops *c, t_ops *head, int cSize)
{
	while (a->csize)
	{
		c->c[4] = a->csize > (cSize * 1.5) ? cSize : a->csize;
		int chunk[c->c[4]];

		set_smallest_chunk(*a, chunk, c->c[4]);
		c->c[0] = -1;
		while ((c->c[0] += 1) < c->c[4])
		{
			int pos[c->c[4]];

			c->c[1] = 0;
			c->c[2] = recalibrate(*a, chunk, pos, c->c[4]);
			c->c[3] = a->msize;

			do
				find_best_move(a, b, c, pos);
			while (smallest(c->sOpts[0], 4) != 0 && (c->c[1] += 1) < c->c[2]);
			rot(a, b, head, get_index(c->sOpts[0], 4), c->m2T[0], c->m2T[1]);
			push(b, a, head, 1);
		}
	}

	push_back_largest(a, b, head);
}

int		main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	t_algo_ops c;
	t_ops head;

	if (argc > 1)
	{
		head.size = 0;
		head.next = NULL;
		
		if (check_int(argc, argv, &a, &b))
		{
			if (check_order(a) == 1 && !b.csize)
				terminate(&a, &b, &head, true);
			else if (a.msize < 10)
				exec_simple_ops(&a, &b, &head);
			else
				exec_ops(&a, &b, &c, &head, a.msize < 250 ? 24 : 45);
		}

		terminate(&a, &b, &head, false);
	}

	return (EXIT_SUCCESS);
}