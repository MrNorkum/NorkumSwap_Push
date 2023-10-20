#include "libmy.h"
#include <stdlib.h>

char	*my_strdup(const char *s1)
{
	size_t		len;
	char		*dup;

	len = my_strlen(s1) + 1;
	dup = malloc(sizeof(char) * len);
	if (!dup)
		return (0);
	return (my_strlcpy(dup, s1, len), (char *)dup);
}
