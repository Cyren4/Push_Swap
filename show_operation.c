/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:36:03 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/20 21:37:41 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*solo_op(t_file *f, int (*op)(t_file *))
{
	char	*which;

	if (op == &swap)
		which = ft_strdup("s \n");
	if (op == &rotate)
		which = ft_strdup("r \n");
	if (op == &rev_rotate)
		which = ft_strdup("rr \n");
	if ((*op)(f))
	{
		which[ft_strlen(which) - 2] = f->name;
		return (which);
	}
	free(which);
	return (NULL);
}

char	*doubleOp(t_file *f1, t_file *f2, int (*op)(t_file *))
{
	int		r1;
	int		r2;
	char	*which;

	if (op == &swap)
		which = ft_strdup("ss\n");
	if (op == &rotate)
		which = ft_strdup("rr\n");
	if (op == &rev_rotate)
		which = ft_strdup("rrr\n");
	r1 = (*op)(f1);
	r2 = (*op)(f2);
	if (r1 && r2)
		return (which);
	else if (r1 || r2)
	{
		if (r1)
			which[ft_strlen(which) - 2] = f1->name;
		else
			which[ft_strlen(which) - 2] = f2->name;
		return (which);
	}
	free(which);
	return (NULL);
}
