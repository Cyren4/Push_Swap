/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:33:55 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/18 23:21:09 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_file *f)
{
	int	tmp;

	if (emptyFile(f) || f->head->next == NULL)
		return (0);
	tmp = f->head->val;
	f->head->val = f->head->next->val;
	f->head->next->val = tmp;
	return (1);
}

char	*push(t_file *src, t_file *dest)
{
	t_eltFile	*tmp;
	char	*ret;

	if (emptyFile(src))
		return (NULL);
	tmp = src->head;
	src->head = src->head->next;
	if (src->head == NULL)
		src->tail = NULL;
	tmp->next = dest->head;
	if (emptyFile(dest))
		dest->tail = tmp;
	dest->head = tmp;
	src->nbElt--;
	dest->nbElt++;
	ret = ft_strdup("pp\n");
	ret[1] = dest->name;// ft_printf("p%c\n", dest->name);
	return (ret);
}

int	rotate(t_file *f)
{
	if (emptyFile(f) || f->head == f->tail)
		return (0);
	f->tail->next = f->head;
	f->tail = f->head;
	f->head = f->head->next;
	f->tail->next = NULL;
	return (1);
}

int	rev_rotate(t_file *f)
{
	t_eltFile	*new_tail;

	if (emptyFile(f) || f->head == f->tail)
		return (0);
	new_tail = f->head;
	while (new_tail->next->next != NULL)
		new_tail = new_tail->next;
	f->tail->next = f->head;
	f->head = f->tail;
	f->tail = new_tail;
	new_tail->next = NULL;
	return (1);
}
