#include "swap_push.h"

static int	first_part(program_t *x, char *line)
{
	if (!my_strncmp(line, "sa\n", 3))
		swap(&x->a);
	else if (!my_strncmp(line, "sb\n", 3))
		swap(&x->b);
	else if (!my_strncmp(line, "ra\n", 3))
		rev(x->a);
	else if (!my_strncmp(line, "rb\n", 3))
		rev(x->b);
	else if (!my_strncmp(line, "rra\n", 4))
		rev_rotate(x->a);
	else if (!my_strncmp(line, "rrb\n", 4))
		rev_rotate(x->b);
	else if (!my_strncmp(line, "pa\n", 3))
		push(&x->b, &x->a);
	else if (!my_strncmp(line, "pb\n", 3))
		push(&x->a, &x->b);
	else
		return (0);
	return (1);
}

static int	second_part(program_t *x, char *line)
{
	if (!my_strncmp(line, "ss\n", 3))
	{
		swap(&x->a);
		swap(&x->b);
	}
	else if (!my_strncmp(line, "rr\n", 3))
	{
		rev(x->a);
		rev(x->b);
	}
	else if (!my_strncmp(line, "rrr\n", 4))
	{
		rev_rotate(x->a);
		rev_rotate(x->b);
	}
	else
		return (0);
	return (1);
}

static int	checker_control(program_t *x)
{
	char	*line;

	line = get_line(0);
	while (line)
	{
		if (first_part(x, line))
			;
		else if (second_part(x, line))
			;
		else
		{
			my_printf("Error\n");
			return (free(line), free_function(x, 1), 1);
		}
		free(line);
		line = get_line(0);
	}
	if (!is_sorted(x->a, 'a', x->count) || lstsize(x->b))
		return (0);
	return (1);
}

static void	checker(program_t *x)
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
	if (checker_control(x))
		return (my_printf("\033[0;32mOK\n\033[0;0m"), free_function(x, 1));
	return (my_printf("\033[0;31mKO\n\033[0;0m"), free_function(x, 1));
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
	return (checker(&x), 0);
}
