#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	long			nbr;
	struct s_lst	*next;
}			t_lst;

void	lstpush(t_lst **lst, int number);
int		lstpop(t_lst **lst);
void	lstclear(t_lst **lst);
int		lstsize(t_lst *lst);
char	s(t_lst **lst);
char	p(t_lst **first, t_lst **second);
char	r(t_lst *lst);
char	rr(t_lst *lst);

typedef struct s_ps
{
	char	**arr;
	t_lst	*a;
	t_lst	*b;
	int		has_split;
	int		count;
}			t_ps;

void	free_function(t_ps *ps);
int		my_atoi(t_ps *ps, const char *str, int sign, long res);
int		quicksort_a(t_ps *ps, int len, int count);
int		quicksort_b(t_ps *ps, int len, int count);
int		get_middle(int *pivot, t_lst *lst, int len);
int		is_sorted(t_lst *lst, char c, int len);
void	sort(t_ps *ps, int len);
int		stack_min(t_ps *ps);
int		isnumeric(char *str);
int		repeat(t_lst *stack, int nbr);
void	push_swap(t_ps *ps);

#endif
