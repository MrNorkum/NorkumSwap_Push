#include "swap_push.h"

void	sort(program_t *x, int len)
{
	int	a;
	int	b;
	int	c;

	if (len == 2 && x->a->nbr > x->a->n->nbr)
		my_printf("sa%c", swap(&x->a));
	if (len == 3)
	{
		a = x->a->nbr;
		b = x->a->n->nbr;
		c = x->a->n->n->nbr;
		if (a < b && b < c)
			return ;
		if (a < b && a > c)
			return (my_printf("rra%c", rev_rotate(x->a)), sort(x, 3));
		if (a > c && c > b)
			return (my_printf("ra%c", rev(x->a)), sort(x, 3));
		return (my_printf("sa%c", swap(&x->a)), sort(x, 3));
	}
}

void	quicksort_3a(lst_t **lst, int len)
{
	while (len == 2 || !is_sorted(*lst, 'a', 3))
	{
		if ((*lst)->nbr > (*lst)->n->nbr)
			my_printf("sa%c", swap(lst));
		else if (len == 3)
			my_printf("ra%csa%crra%c", rev(*lst), swap(lst), rev_rotate(*lst));
		if (len == 2)
			return ;
	}
}

void	quicksort_3b(program_t *x, int len)
{
	if (len == 1)
		my_printf("pa%c", push(&x->b, &x->a));
	else if (len == 2)
	{
		if (x->b->nbr < x->b->n->nbr)
			my_printf("sb%c", swap(&x->b));
		while (len--)
			my_printf("pa%c", push(&x->b, &x->a));
	}
	else if (len == 3)
	{
		while (len)
		{
			if (len == 1 && x->a->nbr > x->a->n->nbr)
				my_printf("sa%c", swap(&x->a));
			else if (len == 1 || (len >= 2 && x->b->nbr > x->b->n->nbr)
				|| (len == 3 && x->b->nbr > x->b->n->n->nbr))
				my_printf("pa%c", push(&x->b, &x->a) * (--len != -1));
			else
				my_printf("sb%c", swap(&x->b));
		}
	}
	return ;
}

int	quicksort_b(program_t *x, int len, int count)
{
	int	pivot;
	int	items;

	if (!count && is_sorted(x->b, 'b', len))
		while (len--)
			my_printf("pa%c", push(&x->b, &x->a));
	if (len <= 3)
		return (quicksort_3b(x, len), 1);
	items = len;
	if (!get_middle(&pivot, x->b, len))
		return (0);
	while (len != items / 2)
	{
		if (x->b->nbr >= pivot && len--)
			my_printf("pa%c", push(&x->b, &x->a));
		else if (++count)
			my_printf("rb%c", rev(x->b));
	}
	while (items / 2 != lstsize(x->b) && count--)
		my_printf("rrb%c", rev_rotate(x->b));
	return (quicksort_a(x, items / 2 + items % 2, 0)
		&& quicksort_b(x, items / 2, 0));
}

int	quicksort_a(program_t *x, int len, int count)
{
	int	pivot;
	int	items;

	if (is_sorted(x->a, 'a', len))
		return (1);
	items = len;
	if (len <= 3)
	{
		if (lstsize(x->a) == 3)
			return (sort(x, 3), 1);
		return (quicksort_3a(&x->a, len), 1);
	}
	if (!get_middle(&pivot, x->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (x->a->nbr < pivot && (len--))
			my_printf("pb%c", push(&x->a, &x->b));
		else if (++count)
			my_printf("ra%c", rev(x->a));
	}
	while (items / 2 + items % 2 != lstsize(x->a) && count--)
		my_printf("rra%c", rev_rotate(x->a));
	return (quicksort_a(x, items / 2 + items % 2, 0)
		&& quicksort_b(x, items / 2, 0));
}
