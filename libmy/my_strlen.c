#include <sys/_types/_size_t.h>

size_t	my_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}
