/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:55:42 by jordan_maco       #+#    #+#             */
/*   Updated: 2018/09/01 14:04:48 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_inst(t_ops *head)
{
	t_ops *temp;

	head = head->next;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	terminate(t_stack *a, t_stack *b, t_ops *head, int flag)
{
	// print_inst(head);
	ft_putstr_fd("JJ\n", 2);

	if (a->msize) {
		free(a->stk);
		ft_putstr_fd("JJ\n", 2);
	}
	if (b->msize)
		free(b->stk);
	free_inst(head);
	flag ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
}

void	push_back_largest(t_stack *a, t_stack *b, t_ops *head)
{
	int i;
	int maxPos[2];

	while (b->csize)
	{
		i = 0;
		maxPos[1] = i;
		maxPos[0] = b->stk[i];
		while (++i < b->csize)
			if (b->stk[i] > maxPos[0])
			{
				maxPos[1] = i;
				maxPos[0] = b->stk[i];
			}
		if (maxPos[1] <= (b->csize / 2))
			while (b->stk[0] != maxPos[0])
				rotate_left(b, head, 1);
		else
			while (b->stk[0] != maxPos[0])
				rotate_right(b, head, 1);
		push(a, b, head, 0);
	}
	
	terminate(a, b, head, true);
}

void	push_back(t_stack *a, t_stack *b, t_ops *head)
{
	int i;

	while (b->csize)
	{
		i = get_position(*a, b->stk[0]);
		int v = a->stk[i];
		if (i <= (b->csize / 2))
			while (a->stk[0] != v)
				rotate_left(a, head, 0);
		else
			while (a->stk[0] != v)
				rotate_right(a, head, 0);
		push(a, b, head, 0);
	}

	while (!b->csize && check_order(*a) != 1)
	{
		if (get_index(a->stk, a->csize) <= (a->csize / 2))
			rotate_left(a, head, 0);
		else
			rotate_right(a, head, 0);
	}
	
	terminate(a, b, head, true);
}

void	exec_simple_ops(t_stack *a, t_stack *b, t_ops *head)
{
	while (!check_order(*a) && a->csize > 3)
		push(b, a, head, 1);
	if (!check_order(*a) && a->csize < 4)
	{
		if (b->csize > 1 && b->stk[1] > b->stk[0])
		{
			ft_swap(&a->stk[0], &a->stk[1]);
			ft_swap(&b->stk[0], &b->stk[1]);
			add_inst(head, "ss");
		}
		else
		{
			ft_swap(&a->stk[0], &a->stk[1]);
			add_inst(head, "sa");
		}
	}

	push_back(a, b, head);
}