/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 12:08:43 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/29 20:37:22 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../../libft/includes/libft.h"
# define MAXINT 2147483647
# define MININT -2147483648

typedef	struct	s_stack
{
	int			msize;
	int			csize;
	int			*stk;
}               t_stack;

typedef	struct	s_ops
{
	int				size;
	char			ops[4];
	struct s_ops	*next;	
}				t_ops;

int				check_int(int argc, char **argv, t_stack *a, t_stack *b);
int				check_order(t_stack a);
void    		shift_left(t_stack *a, t_ops *cnode, int s);
void    		shift_right(t_stack *a, t_ops *cnode, int s);
void    		push(t_stack *a, int b, t_ops *cnode, int s);
int     		pop(t_stack *a, t_ops *cnode, int s);
void			print_stk(t_stack a, t_stack b);
void			add_inst(t_ops *head, char *inst);
void			print_inst(t_ops *head);
void			free_inst(t_ops *head);
void			get_minmax(t_stack a, int minmax[2]);
void			get_neighbours(t_stack a, int b, int c, int neighbours[2]);
void			get_shiftdir(int size, int i, int *n);

#endif
