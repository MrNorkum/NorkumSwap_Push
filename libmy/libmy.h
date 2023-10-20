#ifndef LIBMY_H
# define LIBMY_H

# include <sys/_types/_size_t.h>
# include <stdarg.h>

//LIBFT
size_t	my_strlen(const char *s);
size_t	my_strlcpy(char *dst, const char *src, size_t dstsize);
char	*my_strchr(const char *s, int c);
int		my_strncmp(const char *s1, const char *s2, size_t n);
char	*my_strdup(const char *s1);
char	*my_substr(char const *s, unsigned int start, size_t len);
char	*my_strjoin(char const *s1, char const *s2);
char	**my_free(char **arr, int i);
int		word_count(char const *s, char c);
char	**my_split(char const *s, char c);
void	my_sort_int_tab(int *arr, int size);

//GET_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

char	*get_line(int fd);
char	*get_line_bonus(int fd);

//MY_PRINTF
# define DEC "0123456789"
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"

typedef struct printf_s
{
	va_list		args;
	char		f;
	int			len;
}		printf_t;

int		my_printf(const char *s, ...);

#endif
