#include "push_swap.h"

static inline void	push_swap(program_t *x)
{
	int	i;
	int	num;

	i = -1;
	while (++i < x->count)
	{
		if (!isnumeric(x->arr[i]))
		{
			if (x->has_split)
				my_free(x->arr, 0);
			return (my_printf("Error\n"), exit(1));
		}
	}
	while (--i > -1)
	{
		num = my_atoi(x, x->arr[i], 1, 0);
		if (repeat(x->a, num))
			return (my_printf("Error\n"), free_function(x, 1));
		lstpush(&x->a, num);
	}
	if (2 <= x->count && x->count <= 3)
		sort(x, x->count);
	else if (x->count > 3)
		quicksort_a(x, x->count, 0);
}

int	main(int ac, char **av)
{
	program_t	x;

	x.a = NULL;
	x.b = NULL;
	x.has_split = 0;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		x.arr = my_split(av[1], 32);
		if (!x.arr)
			return (my_printf("Error\n"), 1);
		x.has_split = 1;
		x.count = word_count(av[1], 32);
	}
	else
	{
		x.arr = av + 1;
		x.count = ac - 1;
	}
	return (push_swap(&x), free_function(&x, 0), 0);
}

/*while (ps.a)
        ft_printf("%d\n", lstpop(&ps.a));
    ft_printf("-\na\n\n");
    while (ps.b)
        ft_printf("%d\n", lstpop(&ps.b));
    ft_printf("-\nb\n");
*/
