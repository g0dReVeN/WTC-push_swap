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

void	exec_dop(t_stack *a, t_stack *b, char **ops, char *op)
{
	if (!ft_strcmp(op, ops[8]))
	{
		ft_swap(&a->stk[0], &a->stk[1]);
		ft_swap(&b->stk[0], &b->stk[1]);
	}
	else if (!ft_strcmp(op, ops[9]))
	{
		shift_left(a);
		shift_left(b);
	}
	else if (!ft_strcmp(op, ops[10]))
	{
		shift_right(a);
		shift_right(b);
	}
}

void	exec_op(t_stack *a, t_stack *b, char **ops, char *op)
{
	if (!ft_strcmp(op, ops[0]))
		ft_swap(&a->stk[0], &a->stk[1]);
	else if (!ft_strcmp(op, ops[1]))
		ft_swap(&b->stk[0], &b->stk[1]);
	else if (!ft_strcmp(op, ops[2]))
		push(a, pop(b));
	else if (!ft_strcmp(op, ops[3]))
		push(b, pop(a));
	else if (!ft_strcmp(op, ops[4]))
		shift_left(a);
	else if (!ft_strcmp(op, ops[5]))
		shift_left(b);
	else if (!ft_strcmp(op, ops[6]))
		shift_right(a);
	else if (!ft_strcmp(op, ops[7]))
		shift_right(b);
	else
		exec_dop(a, b, ops, op);
}

int		check_op(t_stack *a, t_stack *b, char *op)
{
	char	*ops[11];
	int		i;

	ops[0] = "sa";
	ops[1] = "sb";
	ops[2] = "pa";
	ops[3] = "pb";
	ops[4] = "ra";
	ops[5] = "rb";
	ops[6] = "rra";
	ops[7] = "rrb";
	ops[8] = "ss";
	ops[9] = "rr";
	ops[10] = "rrr";
	i = -1;
	while (++i < 11)
		if (!ft_strcmp(op, ops[i]))
		{
			exec_op(a, b, ops, op);
			//print_stack(a, b);
			return (1);
		}
	return (0);
}

void	free_stk(t_stack *a, t_stack *b)
{
	if (a->msize)
		free(a->stk);
	if (b->msize)
		free(b->stk);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	char		*line;
	int			gnl;

	if (argc > 1)
	{
		if (check_int(argc, argv, &a, &b))
		{
			while ((gnl = get_next_line(0, &line)) && check_op(&a, &b, line))
				ft_strdel(&line);
			if (gnl == 0)
				(check_order(a) == 1) ? ft_putstr("OK\n") : ft_putstr("KO\n");
			print_stk(a, b);
			free_stk(&a, &b);
			(gnl != 0) ? ft_strdel(&line) : exit(0);
		}
		free_stk(&a, &b);
		ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
