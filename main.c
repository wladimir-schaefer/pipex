#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **environ)
{
	int	i;
	int	*fd;

	fd = malloc(argc * sizeof(char *));
	i = 1;
	if (argc >= 4)
	{
		while (i < argc)
		{
			if (i == 1)
			{
				fd[i] = open(argv[1], O_RDONLY);
				printf("%s\n", argv[1]);
				// if (fd < 2)
				// 	error();
			}
			else if (i == argc - 1)
			{
				fd[i] = open(argv[i], O_CREAT, O_WRONLY, O_TRUNC);
				printf("%s\n", argv[i]);
				// if (fd < 2)
				// 	error();
			}
			else
			{
				if (check_command(argv[i], environ))
				{

				}
			}
			i++;
		}
		// free(fd);
	}

	// else
	// 	error();
}

int	check_command(char *command, char **environ)
{
	char	**pathes;
	char	*path;
	int		i;

	pathes = get_pathes(environ);
	// if (!pathes)
		// 	error();
	i = 0;
	while (pathes[i])
	{
		path = ft_strjoin(pathes[i], "/");
		path = ft_strjoin(path, command);
		if (access(path, F_OK) == 0)
		{
			// free(pathes);
			// free(path);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**get_pathes(char **environ)
{
	char	**pathes;

	while (*environ)
	{
		if (!(ft_strncmp(*environ, "PATH=", 5)))
		{
			pathes = ft_split(*environ + 5, ':');
			return (pathes);
		}
		environ++;
	}
	return (NULL);
}
