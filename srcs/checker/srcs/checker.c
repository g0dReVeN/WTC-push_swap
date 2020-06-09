/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:57:31 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/29 20:33:47 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_stk(t_stack *a, t_stack *b, int flag)
{
	if (a->msize)
		free(a->stk);
	if (b->msize)
		free(b->stk);
	
	flag ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
}

int		exec_dual_op(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, SS))
	{
		if (a->csize > 1)
			ft_swap(&a->stk[0], &a->stk[1]);
		if (b->csize > 1)
			ft_swap(&b->stk[0], &b->stk[1]);
	}
	else if (!ft_strcmp(op, RR))
	{
		rotate(a, 1);
		rotate(b, 1);
	}
	else if (!ft_strcmp(op, RRR))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else
		return false;
	return true;
}

int		exec_op(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, SA))
		if (a->csize > 1)
			ft_swap(&a->stk[0], &a->stk[1]);
	else if (!ft_strcmp(op, SB))
		if (b->csize > 1)
			ft_swap(&b->stk[0], &b->stk[1]);
	else if (!ft_strcmp(op, PA))
		push(a, b);
	else if (!ft_strcmp(op, PB))
		push(b, a);
	else if (!ft_strcmp(op, RA))
		rotate(a, 1);
	else if (!ft_strcmp(op, RB))
		rotate(b, 1);
	else if (!ft_strcmp(op, RRA))
		rotate(a, 0);
	else if (!ft_strcmp(op, RRB))
		rotate(b, 0);
	else
		return exec_dual_op(a, b, op) ? true : false;
	return true;
}

int		main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	char *line;
	int gnl;

	if (argc > 1)
	{
		if (check_int(argc, argv, &a, &b))
		{
			while ((gnl = get_next_line(0, &line)) && exec_op(&a, &b, line))
				ft_strdel(&line);

			if (line)
				ft_strdel(&line);

			if (!gnl) 
			{
				(check_order(a) == 1) ? ft_putstr("OK\n") : ft_putstr("KO\n");
				free_stk(&a, &b, true);
			}
		}
		ft_putstr_fd("Error\n", 2);
		free_stk(&a, &b, false);
	}
	return (EXIT_SUCCESS);
}