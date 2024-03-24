#include "swap_push.h"

void	lstpush(lst_t **lst, int number)
{
	lst_t	*new;

	new = (lst_t *)malloc(sizeof(lst_t));
	if (!lst || !new)
		return ;
	new->nbr = number;
	new->n = *lst;
	*lst = new;
}

int	lstpop(lst_t **lst)
{
	lst_t	*nbrs;
	int		nbr;

	nbrs = (*lst);
	*lst = (*lst)->n;
	nbr = nbrs->nbr;
	free(nbrs);
	return (nbr);
}

int	lstsize(lst_t *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->n;
		i++;
	}
	return (i);
}

void	lstclear(lst_t **lst)
{
	lst_t	*nbrs;

	if (!lst)
		return ;
	while (*lst)
	{
		nbrs = (*lst);
		free(nbrs);
		*lst = (*lst)->n;
	}
}

void	free_function(program_t *x, int e)
{
	if (x->has_split)
		my_free(x->arr, 0);
	lstclear(&x->a);
	lstclear(&x->b);
	if (e == 1)
		exit(1);
}
