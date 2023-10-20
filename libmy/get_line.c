#include "libmy.h"
#include <stdlib.h>
#include <unistd.h>

static inline void	*my_free_stash(char **stash, int create_line)
{
	char	*line;

	if (*stash && !create_line)
		return (free(*stash), *stash = NULL);
	else if (*stash && create_line)
		return (line = my_strdup(*stash), free(*stash), *stash = NULL, line);
	return (NULL);
}

static inline char	*my_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = my_strchr(stash, '\n') - stash;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i + 1)
		line[j] = stash[j];
	return (line[j] = '\0', line);
}

static inline char	*my_recreate_stash(char *stash)
{
	char	*res;

	if (!stash)
		return (NULL);
	if (!*(my_strchr(stash, '\n') + 1))
		return (my_free_stash(&stash, 0));
	res = my_strdup(my_strchr(stash, '\n') + 1);
	return (my_free_stash(&stash, 0), res);
}

char	*get_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*stash = NULL;
	char		*line;
	char		*res;

	ret = BUFFER_SIZE;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == 0 && !stash) || ret == -1)
			return (my_free_stash(&stash, 0));
		buf[ret] = '\0';
		res = my_strjoin(stash, buf);
		my_free_stash(&stash, 0);
		stash = res;
		if (my_strchr(stash, '\n'))
		{
			line = my_extract_line(stash);
			if (!line)
				return (my_free_stash(&stash, 0));
			return (stash = my_recreate_stash(stash), line);
		}
	}
	return (my_free_stash(&stash, 1));
}

char	*get_line_bonus(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*stash[4096];
	char		*line;
	char		*res;

	ret = BUFFER_SIZE;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == 0 && !stash[fd]) || ret == -1)
			return (my_free_stash(&stash[fd], 0));
		buf[ret] = '\0';
		res = my_strjoin(stash[fd], buf);
		my_free_stash(&stash[fd], 0);
		stash[fd] = res;
		if (my_strchr(stash[fd], '\n'))
		{
			line = my_extract_line(stash[fd]);
			if (!line)
				return (my_free_stash(&stash[fd], 0));
			return (stash[fd] = my_recreate_stash(stash[fd]), line);
		}
	}
	return (my_free_stash(&stash[fd], 1));
}
