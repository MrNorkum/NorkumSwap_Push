#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	ps;

	ps.a = NULL;
	ps.b = NULL;
	ps.has_split = 0;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		ps.arr = ft_split(av[1], 32);
		if (!ps.arr)
			return (ft_printf("Error\n"), 1);
		ps.has_split = 1;
		ps.count = wc(av[1], 32);
	}
	else
	{
		ps.arr = av + 1;
		ps.count = ac - 1;
	}
	return (push_swap(&ps), free_function(&ps), 0);
}

/*while (ps.a)
        ft_printf("%d\n", lstpop(&ps.a));
    ft_printf("-\na\n\n");
    while (ps.b)
        ft_printf("%d\n", lstpop(&ps.b));
    ft_printf("-\nb\n");
*/
