#include "libmy.h"
#include <stdlib.h>

char	**my_free(char **arr, int i)
{
	while (arr[i])
		free(arr[i++]);
	return (free(arr), NULL);
}

int	word_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	return (i);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	if (!*s)
		return (0);
	while (*s && *s++ != c)
		len++;
	return (len);
}

char	**my_split(char const *s, char c)
{
	char	**res;
	int		a;
	int		i;

	a = -1;
	i = 0;
	res = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !res)
		return (NULL);
	while (++a < word_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		res[a] = my_substr(s, i, word_len(&s[i], c));
		if (!res[a])
			return (my_free(res, 0));
		i += word_len(&s[i], c);
	}
	return (res[a] = NULL, res);
}
