/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 12:08:43 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/29 20:35:31 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../../libft/includes/libft.h"
# define MAXINT 2147483647
# define MININT -2147483648

typedef	struct	s_stack
{
	int			msize;
	int			csize;
	int			*stk;
}               t_stack;

int				check_int(int argc, char **argv, t_stack *a, t_stack *b);
int				check_order(t_stack a);
void    		shift_left(t_stack *a);
void    		shift_right(t_stack *a);
void    		push(t_stack *a, int b);
int     		pop(t_stack *a);
void			print_stk(t_stack a, t_stack b);

#endif
