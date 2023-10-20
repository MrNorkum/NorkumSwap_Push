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

int	my_atoi(program_t *x, const char *str, int sign, long res)
{
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (48 <= *str && *str <= 57)
		res = res * 10 + *str++ - 48;
	if (res * sign < -2147483648 || res * sign > 2147483647)
		return (my_printf("Error\n"), free_function(x, 1), 0);
	return (res * sign);
}

int	repeat(lst_t *stack, int nbr)
{
	if (!stack)
		return (0);
	if (stack->nbr == nbr)
		return (1);
	return (repeat(stack->n, nbr));
}

int	is_sorted(lst_t *lst, char c, int len)
{
	while (c == 'a' && --len)
	{
		if (lst->nbr > lst->n->nbr)
			return (0);
		lst = lst->n;
	}
	while (c == 'b' && --len)
	{
		if (lst->nbr < lst->n->nbr)
			return (0);
		lst = lst->n;
	}
	return (1);
}

int	get_middle(int *pivot, lst_t *lst, int len)
{
	int	*arr;
	int	tmp;

	arr = (int *)malloc(sizeof(int) * len);
	tmp = len;
	if (!arr)
		return (0);
	while (tmp--)
	{
		arr[tmp] = lst->nbr;
		lst = lst->n;
	}
	my_sort_int_tab(arr, len);
	return (*pivot = arr[len / 2], free(arr), 1);
}
