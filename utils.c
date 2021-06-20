/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:23:42 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/20 21:42:40 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	asc(int cur, int next)
{
	return (cur < next);
}

int	desc(int cur, int next)
{
	return (cur > next);
}

void	find(t_file *a, t_file *b, int (*test)(int, int))
{
	int			found;
	int			i;
	int			(*op)(t_file *);
	t_eltFile	*tmp;
	t_file		*which;

	which = b;
	if (a->name == 'a')
		which = a;
	i = 0;
	found = a->head->val;
	tmp = a->head;
	while (tmp)
	{
		if (test(tmp->val, found))
		{
			found = tmp->val;
			op = &rev_rotate;
			if (i <= a->nbElt / 2)
				op = &rotate;
		}
		tmp = tmp->next;
		i++;
	}
	while (a->head->val != found)
		which->trie = ft_strjoin(which->trie, solo_op(a, op));
	which->trie = ft_strjoin(which->trie, push(a, b));
}

void	findMin(t_file *a, t_file *b)
{
	find(a, b, &asc);
}

void	findMax(t_file *a, t_file *b)
{
	find(a, b, &desc);
}
