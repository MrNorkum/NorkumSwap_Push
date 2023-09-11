#include "push_swap.h"

static inline int	isnumeric(char *str)
{
	if (*str == 43 || *str == 45)
		str++;
	if (!*str)
		return (0);
	while (*str)
		if (!('0' <= *str && *str++ <= '9'))
			return (0);
	return (1);
}

static inline int	repeat(t_lst *stack, int nbr)
{
	if (!stack)
		return (0);
	if (stack->nbr == nbr)
		return (1);
	return (repeat(stack->next, nbr));
}

void	push_swap(t_ps *ps)
{
	int	i;
	int	num;

	i = -1;
	while (++i < ps->count)
	{
		if (!isnumeric(ps->arr[i]))
		{
			if (ps->has_split)
				free_malloc(ps->arr, 0);
			return (ft_printf("Error\n"), exit(1));
		}
	}
	while (--i > -1)
	{
		num = my_atoi(ps, ps->arr[i], 1, 0);
		if (repeat(ps->a, num))
			return (ft_printf("Error\n"), free_function(ps), exit(1));
		lstpush(&ps->a, num);
	}
	if (2 <= ps->count && ps->count <= 3)
		sort(ps, ps->count);
	else if (ps->count <= 4)
		quicksort_a(ps, ps->count, 0);
}

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
