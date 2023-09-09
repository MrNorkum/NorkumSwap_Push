#include "push_swap.h"

int	isnumeric(char *str)
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

int	repeat(t_lst *stack, int nbr)
{
	if (!stack)
		return (0);
	if (stack->nbr == nbr)
		return (1);
	return (repeat(stack->next, nbr));
}

void	finish(t_ps *ps)
{
	if (ps->count == 1)
		return (exit(1));
	if (ps->count <= 3)
		sort(ps, ps->count);
	else
		quicksort_a(ps, ps->count, 0);
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
			return (ft_printf("Error\n"), exit(1));
		lstpush(&ps->a, num);
	}
	finish(ps);
}
