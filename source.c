#include "swap_push.h"

char	swap(lst_t **lst)
{
	if (!*lst || !(*lst)->n)
		return (10);
	(*lst)->nbr = (*lst)->nbr + (*lst)->n->nbr;
	(*lst)->n->nbr = (*lst)->nbr - (*lst)->n->nbr;
	return ((*lst)->nbr = (*lst)->nbr - (*lst)->n->nbr, 10);
}

char	push(lst_t **first, lst_t **second)
{
	return (lstpush(second, lstpop(first)), 10);
}

char	rev(lst_t *lst)
{
	while (lst->n)
	{
		swap(&lst);
		lst = lst->n;
	}
	return (10);
}

char	rev_rotate(lst_t *lst)
{
	if (!lst->n)
		return (10);
	return (rev_rotate(lst->n), swap(&lst), 10);
}
