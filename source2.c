#include "push_swap.h"

int	is_sorted(t_lst *lst, char c, int len)
{
	while (c == 'a' && --len)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	while (c == 'b' && --len)
	{
		if (lst->nbr < lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	get_middle(int *pivot, t_lst *lst, int len)
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
		lst = lst->next;
	}
	ft_sort_int_tab(arr, len);
	return (*pivot = arr[len / 2], free(arr), 1);
}

int	my_atoi(t_ps *ps, const char *str, int sign, long res)
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
		return (free_function(ps), ft_printf("Error\n"), exit(1), 0);
	return (res * sign);
}
