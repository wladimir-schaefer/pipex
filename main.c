#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **environ)
{
	int		fd[2];
	int		fd_in;
	int		fd_out;
	pid_t	cpid[2];
	char	*path;
	char	**args;
	int		i;

	i = 2;
	if (argc >= 5)
	{
		pipe(fd);
		cpid[0] = fork();
		if (cpid[0] == 0 && i == 2)
		{
			fd_in = open_infile(argv[1]);
			dup2(fd_in, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			close_fd(fd_in, fd[0], fd[1]);
			path = get_path(argv[2], environ);
			printf("%s", path);
			args = get_args(argv[2]);
			execve(path, args, environ);
			
		}
		i++;
		cpid[1] = fork();
		if (cpid[1] == 0 && i == 3)
		{
			fd_out = open_outfile(argv[argc - 1]);
			dup2(fd_out, STDOUT_FILENO);
			dup2(fd[0], STDIN_FILENO);
			close_fd(fd_out, fd[0], fd[1]);
			path = get_path(argv[3], environ);
			args = get_args(argv[3]);
			execve(path, args, environ);
		}
		close(fd[0]);
		close(fd[1]);
		for (int i = 0; i < 2; i++)
			wait(NULL);
	}
	// else
	// 	error();
}

int	open_infile(char *file1)
{
	int	fd;

	fd = open(file1, O_RDONLY);
	return (fd);
	// 	error();
}

int	open_outfile(char *file2)
{
	int	fd;

	fd = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (fd);
	// 	error();
}

char	*get_path(char *command, char **environ)
{
	char	**pathes;
	char	**splitted_command;
	char	*path;
	int		i;

	pathes = get_pathes(environ);
	// if (!pathes)
		// 	error();
	splitted_command = ft_split(command, ' ');
	// if (!split)
		// 	error();
	i = 0;
	while (pathes[i])
	{
		path = ft_strjoin(pathes[i], "/");
		path = ft_strjoin(path, splitted_command[0]);
		if (access(path, F_OK) == 0)
		{
			// free(pathes);
			// free(path);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	**get_args(char *command)
{
	char	**args;

	args = ft_split(command, ' ');
	// if (!split)
		// 	error();
	return (args);
}

char	**get_pathes(char **environ)
{
	char	**pathes;

	while (*environ)
	{
		if (!(ft_strncmp(*environ, "PATH=", 5)))
		{
			pathes = ft_split(*environ + 5, ':');
			// if (!split)
				// 	error();
			return (pathes);
		}
		environ++;
	}
	return (NULL);
}

int	close_fd(int n, ...)
{
	va_list	args;
	int		res;
	int		i;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		res = close(va_arg(args, int));
		if (res != 0)
			return (res);
		i++;
	}
	va_end(args);
	return (0);
}