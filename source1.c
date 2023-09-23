#include "push_swap.h"

void	lstpush(t_lst **lst, int number)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!lst || !new)
		return ;
	new->nbr = number;
	new -> next = *lst;
	*lst = new;
}

int	lstpop(t_lst **lst)
{
	t_lst	*nbrs;
	int		nbr;

	nbrs = (*lst);
	nbr = nbrs->nbr;
	free(nbrs);
	*lst = (*lst)->next;
	return (nbr);
}

int	lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	lstclear(t_lst **lst)
{
	t_lst	*nbrs;

	if (!lst)
		return ;
	while (*lst)
	{
		nbrs = (*lst);
		free(nbrs);
		*lst = (*lst)->next;
	}
}

void	free_function(t_ps *ps, int e)
{
	if (ps->has_split)
		free_malloc(ps->arr, 0);
	lstclear(&ps->a);
	lstclear(&ps->b);
	exit(e);
}

