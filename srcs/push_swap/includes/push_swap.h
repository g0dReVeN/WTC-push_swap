/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 12:08:43 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/31 17:51:18 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "../../../libft/includes/libft.h"
#define get_index ft_get_smallest_int_index
#define smallest ft_get_smallest_int
#define get_index_l ft_get_largest_int_index
#define largest ft_get_largest_int

typedef struct	s_stack
{
	int msize;
	int csize;
	int *stk;
}				t_stack;

typedef struct	s_ops
{
	int size;
	char ops[4];
	struct s_ops *next;
}				t_ops;

typedef struct	algo_ops
{
	int c[5];	     // [0] => 1st counter [1] => 2nd counter [2] => 3rd counter [3] => bestMove [4] => chunkSize
	int m2T[4][2];   // [0] => moves to top and bot of stack A [1] => moves to top and bot of stack B [2] => temp moves to top and bot of stack A [3] => temp moves to top and bot of stack B
	int sOpts[2][4]; // [0] => shift options [1] => temp shift options 
}				t_algo_ops;

int				check_int(int argc, char **argv, t_stack *a, t_stack *b);
int				check_order(t_stack a);
void			exec_simple_ops(t_stack *a, t_stack *b, t_ops *head);
void			terminate(t_stack *a, t_stack *b, t_ops *head, int flag);
void			push_back_largest(t_stack *a, t_stack *b, t_ops *head);
void			push_back(t_stack *a, t_stack *b, t_ops *head);
void			rotate_left(t_stack *a, t_ops *cnode, int s);
void			rotate_right(t_stack *a, t_ops *cnode, int s);
void			rotate_both_right(t_stack *a, t_stack *b, t_ops *cnode);
void			rotate_both_left(t_stack *a, t_stack *b, t_ops *cnode);
void			push(t_stack *a, t_stack *b, t_ops *cnode, int s);
int				recalibrate(t_stack a, int *value, int *pos, int size);
void			set_smallest_chunk(t_stack a, int *chunk, int size);
int				get_position(t_stack a, int b);
int				get_neighbours(t_stack a, int bMax);
void			find_best_move(t_stack *a, t_stack *b, t_algo_ops *c, int *pos);
void			add_inst(t_ops *head, char *inst);
void			print_inst(t_ops *head);

#endif
