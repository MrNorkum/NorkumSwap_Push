#include "push_swap.h"

static inline int	first_part(t_ps *ps, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		s(&ps->a);
	else if (!ft_strncmp(line, "sb\n", 3))
		s(&ps->b);
	else if (!ft_strncmp(line, "ra\n", 3))
		r(ps->a);
	else if (!ft_strncmp(line, "rb\n", 3))
		r(ps->b);
	else if (!ft_strncmp(line, "rra\n", 4))
		rr(ps->a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rr(ps->b);
	else if (!ft_strncmp(line, "pa\n", 3))
		p(&ps->b, &ps->a);
	else if (!ft_strncmp(line, "pb\n", 3))
		p(&ps->a, &ps->b);
	else
		return (0);
	return (1);
}

static inline int	second_part(t_ps *ps, char *line)
{
	if (!ft_strncmp(line, "ss\n", 3))
	{
		s(&ps->a);
		s(&ps->b);
	}
	else if (!ft_strncmp(line, "rr\n", 3))
	{
		r(ps->a);
		r(ps->b);
	}
	else if (!ft_strncmp(line, "rrr\n", 4))
	{
		rr(ps->a);
		rr(ps->b);
	}
	else
		return (0);
	return (1);
}

static inline int	checker_control(t_ps *ps)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (first_part(ps, line))
			;
		else if (second_part(ps, line))
			;
		else
		{
			ft_printf("\033[0;33mError\n");
			return (free(line), free_function(ps, 0), 1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (!is_sorted(ps->a, 'a', ps->count) || lstsize(ps->b))
		return (0);
	return (1);
}

static inline int	checker(t_ps *ps)
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
			return (ft_printf("\033[0;33mError\n"), exit(1), 1);
		}
	}
	while (--i > -1)
	{
		num = my_atoi(ps, ps->arr[i], 1, 0);
		if (repeat(ps->a, num))
			return (ft_printf("\033[0;33mError\n"), free_function(ps, 1), 1);
		lstpush(&ps->a, num);
	}
	if (checker_control(ps))
		return (ft_printf("\033[0;32mOK\n"), 0);
	return (ft_printf("\033[0;31mKO\n"), 1);
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
			return (ft_printf("\033[0;33mError\n"), 1);
		ps.has_split = 1;
		ps.count = wc(av[1], 32);
	}
	else
	{
		ps.arr = av + 1;
		ps.count = ac - 1;
	}
	return (checker(&ps), free_function(&ps, 0), 0);
}
