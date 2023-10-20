#include "libmy.h"
#include <stdlib.h>

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = len;
	if (!s)
		return (NULL);
	if (start >= my_strlen(s) || len == 0)
		return (my_strdup(""));
	if (len > my_strlen(s + start))
		i = my_strlen(s + start);
	substr = (char *)malloc(i + 1);
	if (!substr)
		return (NULL);
	return (my_strlcpy(substr, s + start, i + 1), substr);
}
