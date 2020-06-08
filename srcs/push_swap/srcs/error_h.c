/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:40:03 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/29 20:37:03 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_dup(t_stack *a, t_stack *b)
{
	int i;
	int j;

	i = -1;
	while (++i < a->msize)
	{
		j = i;
		while (++j < a->msize)
			if (a->stk[i] == a->stk[j])
				return (0);
	}
	b->msize = a->msize;
	b->stk = malloc(sizeof(int) * a->msize);
	return (1);
}

int		check_isize(int argc, char **argv, t_stack *a, t_stack *b)
{
	int						i;
	int						j;
	long long int			num;
	int						sign;

	i = 0;
	a->stk = malloc(sizeof(int) * a->msize);
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			sign = 1;
			num = 0;
			while (argv[i][j] == '+' || argv[i][j] == '-' || argv[i][j] == ' ')
				(argv[i][j++] == '-') && (sign = -1);
			while (ft_isdigit(argv[i][j]))
				num = num * 10 + argv[i][j++] - '0';
			if ((num * sign) > MAXINT || (num * sign) < MININT)
				return (0);
			else
				a->stk[a->csize++] = num * sign;
		}
	}
	return (check_dup(a, b) ? 1 : 0);
}

int		check_num(char *str, t_stack *a)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-') i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == '\0' || str[i] == ' ') a->msize++;
		if (str[i] == ' ' && (i - 1) >= 0 && !ft_isdigit(str[i - 1])) f++;
		if (f || str[0] == ' ' || (str[i] != '\0' && str[i] != ' '))
		{
			a->msize = 0;
			return (0);
		}
		if (str[i]) i++;
	}
	return (1);
}

int		check_int(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;

	a->msize = 0;
	a->csize = 0;
	b->csize = 0;
	b->msize = 0;
	i = 1;
	while (i < argc)
	{
		if (check_num(argv[i], a))
			i++;	
		else
			return (0);
	}
	return (check_isize(argc, argv, a, b) ? 1 : 0);
}

int     check_order(t_stack a)
{
	int	i;
    int f;
	int	ret;

	i = -1;
    f = 0;
	ret = 0;
	while (++i < (a.csize - 1))
		if (a.stk[i] > a.stk[i + 1])
            f++;
	(f == 0) && (ret = 1);
	(f == 1 && a.stk[a.csize - 1] < a.stk[0]) && (ret = 2);
	return (ret);
}

