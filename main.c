#include "push_swap.h"

void	shortestSort(t_file *a, t_file *b, int nb)
{
	int		i;
	char	*min;
	t_file	*dup;

	i = 0;
	min = NULL;
	while (i < 4)
	{
		dup = duplicateFile(a);
		chunksort(dup, b, nb + i);
		if (min == NULL || ft_strlen(dup->trie) < ft_strlen(min))
			min = ft_strdup(dup->trie);
		clear_file(dup);
		i++;
	}
	printf("%s", min);
}

int	main(int ac, char **av)
{
	t_file	*a;
	t_file	*b;

	a = initFile('a');
	if (a == NULL || !check_args(a, ac, av + 1))
		return (-1);
	if (!order(a, a->nbElt, &asc))
	{
		b = initFile('b');
		if (b == NULL)
			return (clear_file(a));
		if (a->nbElt <= 3)
		{
			sort3(a);
			printf("%s", a->trie);
		}
		else if (a->nbElt < 50)
		{
			sort10(a, b);
			printf("%s", a->trie);
		}
		else if (a->nbElt <= 100)
			shortestSort(a, b, 3);
		else
			shortestSort(a, b, 8);
		clear_file(b);
	}
	clear_file(a);
	return (0);
}
