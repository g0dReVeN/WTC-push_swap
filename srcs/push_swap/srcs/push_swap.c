/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:50:39 by jordan_maco       #+#    #+#             */
/*   Updated: 2018/09/02 21:43:20 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stk(t_stack *a, t_stack *b)
{
	if (a->msize)
		free(a->stk);
	if (b->msize)
		free(b->stk);
}

void	set_order(t_stack *a, t_stack *b, int *min, t_ops *head)
{
	//print_inst(head);
	int	i;
	int	d;

	i = 0;
	d = 0;
	get_minmax(*a, min);
	while (a->stk[++i] != *min)
	{
		if (a->stk[i + 1] == *min)
			get_shiftdir(a->msize, i + 1, &d);
	}
	while (a->stk[0] != *min)
		(d) ? shift_right(a, head, 0) : shift_left(a, head, 0);
	free_stk(a, b);
	print_inst(head);
}

void	push_back(t_stack *a, t_stack *b, t_ops *head)
{
	/*int	minmax[2];
	int	neighbours[2];

	while (b->csize)
	{
		get_minmax(*a, minmax);
		get_neighbours(*a, b->stk[0], minmax[0], neighbours);
		if (b->stk[0] < minmax[0] || b->stk[0] > minmax[1])
		{
			while (a->stk[0] != minmax[0])
				(neighbours[1]) ? shift_right(a, head, 0) : shift_left(a, head, 0);
			push(a, pop(b, head, 2), head, 0);
		}
		else
		{
			while (a->stk[0] != neighbours[0])
				(neighbours[1]) ? shift_right(a, head, 0) : shift_left(a, head, 0);
			push(a, pop(b, head, 2), head, 0);
		}
		//print_stk(*a, *b);
	}
	(check_order(*a) == 1) ? print_inst(head) : set_order(a, b, minmax, head);*/
	int	minmax[2];
	int	i;
	int	d;

	get_minmax(*b, minmax);
	while (!check_order(*b))
	{
		if (!(b->stk[0] == minmax[0] && b->stk[1] == minmax[1]))
		{
			if (b->stk[0] < b->stk[1])
			{
				ft_swap(&b->stk[0], &b->stk[1]);
				add_inst(head, "sb");
			}
			if (b->stk[0] < b->stk[b->csize - 1])
				shift_left(b, head, 1);
			else
				shift_right(b, head, 1);
		}
		else
		{
			shift_left(b, head, 1);
			shift_left(b, head, 1);
		}
	}
	i = 0;
	d = 0;
	while (b->stk[++i] != minmax[1])
	{
		if (b->stk[i + 1] == minmax[1])
			get_shiftdir(b->msize, i + 1, &d);
	}
	while (b->stk[0] != minmax[1])
		(d) ? shift_right(b, head, 0) : shift_left(b, head, 0);
	while (b->csize)
		push(a, pop(b, head, 2), head, 0);
	set_order(a, b, minmax, head);
}

int		get_median(t_stack a)
{
	int	b[a.msize];
	int	i;
	int	j;

	i = -1;
	while (++i < a.msize)
		b[i] = a.stk[i];
	i = -1;
	while (++i < (a.msize - 1))
	{
		j = -1;
		while (++j < (a.msize - i - 1))
			if (b[j] > b[j + 1])
              ft_swap(&b[j], &b[j + 1]);
	}
	return (b[a.msize / 2]);
}

void	partiton(t_stack *a, t_stack *b, t_ops *head)
{
	int		pivot;
	int		half;
	
	pivot = get_median(*a);
	half = 0;
	while (half < (a->msize / 2))
	{
		if (a->stk[0] < pivot && half < (a->msize / 2))
		{
			push(b, pop(a, head, 2), head, 1);
			half++;
		}
		else
			shift_left(a, head, 0);
		if (check_order(*a))
			break ;
	}
}

void	get_ops(t_stack *a, t_stack *b, t_ops *head)
{
	int	minmax[2];

	partiton(a, b, head);
	get_minmax(*a, minmax);
	while (!check_order(*a))
	{
		if (!(a->stk[0] == minmax[1] && a->stk[1] == minmax[0]))
		{
			if (a->stk[0] > a->stk[1])
			{
				ft_swap(&a->stk[0], &a->stk[1]);
				add_inst(head, "sa");
			}
			if (a->stk[0] > a->stk[a->csize - 1])
				shift_left(a, head, 0);
			else
				shift_right(a, head, 0);
		}
		else
		{
			shift_left(a, head, 0);
			shift_left(a, head, 0);
		}
		print_stk(*a, *b);
	}
	push_back(a, b, head);
}

int		main(int argc, char **argv)
{
    t_stack		a;
	t_stack		b;
	t_ops		head;

	if (argc > 1)
	{
		if (check_int(argc, argv, &a, &b))
		{
			head.size = 0;
			head.next = NULL;
			(check_order(a) == 1) ? exit(0) : get_ops(&a, &b, &head);
		}
		free_stk(&a, &b);
		ft_putstr_fd("Error\n", 2);
	}
    return (0);
}
