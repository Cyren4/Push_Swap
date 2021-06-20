/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:33:42 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/20 14:58:40by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cleanErr(t_file *a, t_file *b, char *line)
{
	free(line);
	clear_file(a);
	clear_file(b);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	operation(t_file *a, t_file *b, char *line)
{
	if (ft_strcmp(line, "rrr") == 0)
		doubleOp(a, b, &rev_rotate);
	else if (ft_strcmp(line, "rra") == 0)
		solo_op(a, &rev_rotate);
	else if (ft_strcmp(line, "rra") == 0)
		solo_op(b, &rev_rotate);
	else if (ft_strcmp(line, "rr") == 0)
		doubleOp(a, b, &rotate);
	else if (ft_strcmp(line, "ra") == 0)
		solo_op(a, &rotate);
	else if (ft_strcmp(line, "rb") == 0)
		solo_op(b, &rotate);
	else if (ft_strcmp(line, "ss") == 0)
		doubleOp(a, b, &swap);
	else if (ft_strcmp(line, "sa") == 0)
		solo_op(a, &swap);
	else if (ft_strcmp(line, "sb") == 0)
		solo_op(b, &swap);
	else if (ft_strcmp(line, "pa") == 0)
		push(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		push(a, b);
	else
		cleanErr(a, b, line);
}

static void	printRes(int i)
{
	if (i == 1)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int ac, char **av)
{
	t_file	*a;
	t_file	*b;
	char	*line;
	int		ret;

	a = initFile('a');
	b = initFile('b');
	if (!check_args(a, ac, av + 1))
		return (-1);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(1, &line);
		if (ret < 0)
			return (cleanErr(a, b, line));
		if (ret != 0)
			operation(a, b, line);
		free(line);
	}
	printRes(order(a, a->nbElt, &asc) && emptyFile(b));
	clear_file(a);
	clear_file(b);
	return (0);
}
