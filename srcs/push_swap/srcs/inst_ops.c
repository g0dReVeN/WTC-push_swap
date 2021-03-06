/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 21:23:45 by jordan_maco       #+#    #+#             */
/*   Updated: 2018/09/01 15:46:00 by jordan_maco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_inst(t_ops *head, char *inst)
{
	t_ops *cnode;
	char *dest;

	cnode = malloc(sizeof(t_ops));
	dest = &(cnode->ops[0]);
	dest = ft_strcpy(dest, inst);
	while (head->next)
		head = head->next;
	cnode->size = head->size + 1;
	cnode->next = NULL;
	head->next = cnode;
}

void	print_inst(t_ops *head)
{
	t_ops *print;

	print = head->next;
	while (print)
	{
		ft_putstr_fd(print->ops, 1);
		ft_putchar_fd('\n', 1);
		// if (!print->next)
		// {
		// 	ft_putstr_fd("\nTotal number of instructions = ", 2);
		// 	ft_putnbr_fd(print->size, 2);
		// 	ft_putchar_fd('\n', 2);
		// }
		print = print->next;
	}
}
