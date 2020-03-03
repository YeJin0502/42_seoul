# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

# define GNL_READ 1
# define GNL_END_REACHED 0
# define GNL_ERROR -1

# define GNL_BSIZE0_PROC 1

# define CHECK_PTR_DEF(ptr, def) if (!(ptr)) return (def);
# define CHECK_PTR(ptr) CHECK_PTR_DEF(ptr, NULL);
# define CHECK_PTR_EMPTY(ptr) if (!(ptr)) return ;
# define CHECK_MALLOC(var, size) CHECK_PTR((var = malloc(size)))

# define MIN(a, b) (((a) < (b)) ? (a) : (b))
# define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct		s_gnl_holder
{
	int				initialized;
	int				reached;
	unsigned char	buffer[BUFFER_SIZE];
	size_t			byte_read;
	size_t			offset;
	unsigned char	*stored;
	size_t			stored_length;
}					t_gnl_holder;

int					get_next_line(int fd, char **line);

void				*ft_memcpy(void *dst, const void *src, size_t n);

///////////

int		get_next_line(const int fd, char **line);
int		print_line(const int fd, char **str, char **line);

///////////

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t index;

	if (dst == NULL && src == NULL)
		return (NULL);
	index = 0;
	while (index < n)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}
///////////

static int
	internal_gnl_initialize(t_gnl_holder *holder, int force, int return_value)
{
	if (!(holder->initialized == 1 && !force))
	{
		holder->initialized = 1;
		holder->reached = 0;
		holder->offset = BUFFER_SIZE;
		holder->stored = NULL;
		holder->stored_length = 0;
	}
	return (return_value);
}

static unsigned char
	*internal_gnl_store(t_gnl_holder *holder, int force)
{
	unsigned char	c;
	unsigned char	*new;

	c = holder->buffer[holder->offset];
	holder->offset += 1;
	CHECK_MALLOC(new, (holder->stored_length + 1) * sizeof(char));
	if (holder->stored != NULL)
	{
		ft_memcpy(new, holder->stored, holder->stored_length);
		free(holder->stored);
	}
	if (c == '\n' || force)
	{
		new[holder->stored_length] = '\0';
		holder->stored = NULL;
		holder->stored_length = 0;
		return (new);
	}
	new[holder->stored_length] = c;
	holder->stored_length += 1;
	holder->stored = new;
	return (NULL);
}

static int
	internal_gnl_handle(t_gnl_holder *holder, char **return_line)
{
	unsigned char	*line;
	int				force;

	while (holder->offset + 1 < BUFFER_SIZE + 1)
	{
		force = holder->offset >= holder->byte_read;
		line = internal_gnl_store(holder, force);
		if (line != NULL)
		{
			if (force)
				holder->reached = 1;
			*return_line = (char *)line;
			return (1);
		}
	}
	return (0);
}

#define OPEN_MAX 100

int
	get_next_line(int fd, char **line)
{
	static t_gnl_holder	holders[OPEN_MAX];
	t_gnl_holder		*holder;

	if (line == NULL || BUFFER_SIZE == 0 || fd < 0)
		return (GNL_ERROR);
	*line = NULL;
	holder = (holders + fd);
	internal_gnl_initialize(holder, 0, 1);
	while (1)
	{
		if (holder->offset == BUFFER_SIZE)
		{
			holder->byte_read = read(fd, holder->buffer, BUFFER_SIZE);
			holder->offset = 0;
		}
		if (holder->byte_read == (size_t)-1)
			return (GNL_ERROR);
		if (internal_gnl_handle(holder, line))
		{
			if (holder->byte_read == 0 || holder->reached)
				return (internal_gnl_initialize(holder, 1, GNL_END_REACHED));
			return (GNL_READ);
		}
	}
}
///////////


#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("43_char", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s [%d]\n", line, ret);
		free(line);
	}
	printf("%s [%d]\n", line, ret);
	free(line);
	return (0);
}