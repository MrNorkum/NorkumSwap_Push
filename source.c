#include "push_swap.h"

char	s(t_lst **lst)
{
	if (!*lst || !(*lst)->next)
		return (10);
	(*lst)->nbr = (*lst)->nbr + (*lst)->next->nbr;
	(*lst)->next->nbr = (*lst)->nbr - (*lst)->next->nbr;
	return ((*lst)->nbr = (*lst)->nbr - (*lst)->next->nbr, 10);
}

char	p(t_lst **first, t_lst **second)
{
	return (lstpush(second, lstpop(first)), 10);
}

char	r(t_lst *lst)
{
	while (lst->next)
	{
		s(&lst);
		lst = lst->next;
	}
	return (10);
}

char	rr(t_lst *lst)
{
	if (!lst->next)
		return (10);
	return (rr(lst->next), s(&lst), 10);
}
