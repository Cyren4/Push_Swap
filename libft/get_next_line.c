/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:57:36 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/20 14:46:51 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_clean(char *tmp)
{
	if (tmp != NULL)
		free(tmp);
	return (-1);
}

static char	*lks(char *tmp)
{
	char		*leaks;

	leaks = tmp;
	tmp = ft_substr(tmp, check_n(tmp) + 1, ft_strlen(tmp));
	free(leaks);
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			r;

	r = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	*line = NULL;
	while (check_n(tmp) < 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		if (r == -1)
			return (get_clean(tmp));
		tmp = ft_strjoin2(tmp, buf);
		if (r == 0 && check_n(tmp) < 0)
		{
			*line = ft_substr2(tmp, 0, ft_strlen(tmp));
			free(tmp);
			tmp = NULL;
			return (0);
		}
	}
	*line = ft_substr2(tmp, 0, check_n(tmp));
	tmp = lks(tmp);
	return (1);
}
