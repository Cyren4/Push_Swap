#include "push_swap.h"

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
			return (clear(a));
		if (a->nbElt <= 3)
			sort3(a);
		else if (a->nbElt < 50)
			sort10(a, b);
		else if (a->nbElt <= 100)
			chunksort(a, b, 5);
		else
			chunksort(a, b, 10);
		clear(b);
	}
	clear(a);
	return (0);
}
