/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:16:50 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/20 13:10:44 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_eltFile {
	int					val;
	struct s_eltFile	*next;
}	t_eltFile;

typedef struct s_file{
	char		name;
	int			nbElt;
	t_eltFile	*head;
	t_eltFile	*tail;
	char		*trie;
}	t_file;

/* file.c */
t_file	*initFile(char c);
t_file	*add(t_file *f, int val);
int		emptyFile(t_file *f);
int		clear_file(t_file *f);
t_file	*duplicateFile(t_file *f);

/* operation.c */
char	*solo_op(t_file *f, int (*op)(t_file *));
int		swap(t_file *f);
char	*push(t_file *src, t_file *dest);
int		rotate(t_file *f);
int		rev_rotate(t_file *f);
char	*doubleOp(t_file *f1, t_file *f2, int (*op)(t_file *));

#endif