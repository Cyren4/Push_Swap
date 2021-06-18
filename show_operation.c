/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:36:03 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/17 17:32:47 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solo_op(t_file *f, int (*op)(t_file *))
{
	char	*which;

	if (op == &swap)
		which = ft_strdup("s");
	if (op == &rotate)
		which = ft_strdup("r");
	if (op == &rev_rotate)
		which = ft_strdup("rr");
	if ((*op)(f))
		ft_printf("%s%c\n", which, f->name);
	free(which);
}

void	doubleOp(t_file *f1, t_file *f2, int (*op)(t_file *))
{
	int		r1;
	int		r2;
	char	*which;

	if (op == &swap)
		which = ft_strdup("ss");
	if (op == &rotate)
		which = ft_strdup("rr");
	if (op == &rev_rotate)
		which = ft_strdup("rrr");
	r1 = (*op)(f1);
	r2 = (*op)(f2);
	if (r1 && r2)
		ft_printf("%s\n", which);
	else if (r1 || r2)
	{
		if (r1)
			ft_printf("%s%c\n", which + 1, f1->name);
		else
			ft_printf("%s%c\n", which + 1, f2->name);
	}
	free(which);
}
