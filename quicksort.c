#include "push_swap.h"

void	sort(t_ps *ps, int len)
{
	int	a;
	int	b;
	int	c;

	if (len == 2 && ps->a->nbr > ps->a->next->nbr)
		ft_printf("sa%c", s(&ps->a));
	if (len == 3)
	{
		a = ps->a->nbr;
		b = ps->a->next->nbr;
		c = ps->a->next->next->nbr;
		if (a < b && b < c)
			return ;
		if (a < b && a > c)
			return (ft_printf("rra%c", rr(ps->a)), sort(ps, 3));
		if (a > c && c > b)
			return (ft_printf("ra%c", r(ps->a)), sort(ps, 3));
		return (ft_printf("sa%c", s(&ps->a)), sort(ps, 3));
	}
}

void	quicksort_3a(t_lst **lst, int len)
{
	while (len == 2 || !is_sorted(*lst, 'a', 3))
	{
		if ((*lst)->nbr > (*lst)->next->nbr)
			ft_printf("sa%c", s(lst));
		else if (len == 3)
			ft_printf("ra%csa%crra%c", r(*lst), s(lst), rr(*lst));
		if (len == 2)
			return ;
	}
}

void	quicksort_3b(t_ps *ps, int len)
{
	if (len == 1)
		ft_printf("pa%c", p(&ps->b, &ps->a));
	else if (len == 2)
	{
		if (ps->b->nbr < ps->b->next->nbr)
			ft_printf("sb%c", s(&ps->b));
		while (len--)
			ft_printf("pa%c", p(&ps->b, &ps->a));
	}
	else if (len == 3)
	{
		while (len || !(ps->a->nbr < ps->a->next->nbr
				&& ps->a->next->nbr < ps->a->next->next->nbr))
		{
			if (len == 1 && ps->a->nbr > ps->a->next->nbr)
				ft_printf("sa%c", s(&ps->a));
			else if (len == 1 || (len >= 2 && ps->b->nbr > ps->b->next->nbr)
				|| (len == 3 && ps->b->nbr > ps->b->next->next->nbr))
				ft_printf("pa%c", p(&ps->b, &ps->a) * (--len != -1));
			else
				ft_printf("sb%c", s(&ps->b));
		}
	}
	return ;
}

int	quicksort_a(t_ps *ps, int len, int count)
{
	int	pivot;
	int	items;

	if (is_sorted(ps->a, 'a', len))
		return (1);
	items = len;
	if (len <= 3)
	{
		if (lstsize(ps->a) == 3)
			return (sort(ps, 3), 1);
		return (quicksort_3a(&ps->a, len), 1);
	}
	if (!get_middle(&pivot, ps->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (ps->a->nbr < pivot && (len--))
			ft_printf("pb%c", p(&ps->a, &ps->b));
		else if (++count)
			ft_printf("ra%c", r(ps->a));
	}
	while (items / 2 + items % 2 != lstsize(ps->a) && count--)
		ft_printf("rra%c", rr(ps->a));
	return (quicksort_a(ps, items / 2 + items % 2, 0)
		&& quicksort_b(ps, items / 2, 0));
}

int	quicksort_b(t_ps *ps, int len, int count)
{
	int	pivot;
	int	items;

	if (!count && is_sorted(ps->b, 'b', len))
		while (len--)
			ft_printf("pa%c", p(&ps->b, &ps->a));
	if (len <= 3)
		return (quicksort_3b(ps, len), 1);
	items = len;
	if (!get_middle(&pivot, ps->b, len))
		return (0);
	while (len != items / 2)
	{
		if (ps->b->nbr >= pivot && len--)
			ft_printf("pa%c", p(&ps->b, &ps->a));
		else if (++count)
			ft_printf("rb%c", r(ps->b));
	}
	while (items / 2 != lstsize(ps->b) && count--)
		ft_printf("rrb%c", rr(ps->b));
	return (quicksort_a(ps, items / 2 + items % 2, 0)
		&& quicksort_b(ps, items / 2, 0));
}
