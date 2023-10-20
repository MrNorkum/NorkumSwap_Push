#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libmy/libmy.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct lst_s
{
	long			nbr;
	struct lst_s	*n;
}					lst_t;

void				lstpush(lst_t **lst, int number);
int					lstpop(lst_t **lst);
int					lstsize(lst_t *lst);
void				lstclear(lst_t **lst);
char				swap(lst_t **lst);
char				push(lst_t **first, lst_t **second);
char				rev(lst_t *lst);
char				rev_rotate(lst_t *lst);

typedef struct program_s
{
	char			**arr;
	lst_t			*a;
	lst_t			*b;
	int				has_split;
	int				count;
}					program_t;

void				free_function(program_t *x, int e);
int					isnumeric(char *str);
int					my_atoi(program_t *x, const char *str, int sign, long res);
int					repeat(lst_t *stack, int nbr);
int					get_middle(int *pivot, lst_t *lst, int len);
int					is_sorted(lst_t *lst, char c, int len);
void				sort(program_t *x, int len);
int					quicksort_a(program_t *x, int len, int count);

#endif
