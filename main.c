#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **environ)
{
	t_data	*data;
	int		arg;
	
	data = ft_calloc(1, sizeof(t_data));
		// if (!data)
		// 	error ();
	data->fd = 0;
	data->file1 = argv[1];
	data->file2 = argv[argc - 1];
	make_pipes(data, argc);
	arg = 2;
	if (argc >= 5)
	{
		data->cpid[0] = fork();
		if (data->cpid[0] == 0 && arg == 2)
			exec_left_arg(data, argv[arg], environ);
		arg++;

		data->cpid[1] = fork();
		if (data->cpid[1] == 0 && arg == argc - 2)
			exec_right_arg(data, argv[arg], environ);

		for (int i = 0; i < argc - 4; i++)
		{
			close(data->fds[i * 2]);
			close(data->fds[i * 2 + 1]);
		}
		for (int i = 0; i < 2; i++)
			wait(NULL);
	}
	// else
	// 	error();
}

void	make_pipes(t_data *data, int argc)
{
	int	i;

	data->fds = ft_calloc(argc - 4, sizeof(int));
	// if (!data->fds)
	// 	error();
	i = 0;
	while (i < argc - 4)
	{
		pipe(&data->fds[i * 2]);
		i++;
	}
	for (int i = 0; i < (argc - 4) * 2; i++)
		printf("fd %d = %d\n", i, data->fds[i]);
}

void	exec_left_arg(t_data *data, char *arg, char **environ)
{
	data->fd_in = open_infile(data->file1);
	dup2(data->fd_in, STDIN_FILENO);
	dup2(data->fds[data->fd * 2 + 1], STDOUT_FILENO);
	close_fd(data->fd_in, data->fds[data->fd * 2], data->fds[1]);
	data->path = get_path(arg, environ);
	data->args = get_args(arg);
	execve(data->path, data->args, environ);
}

void	exec_right_arg(t_data *data, char *arg, char **environ)
{
	data->fd_out = open_outfile(data->file2);
	dup2(data->fd_out, STDOUT_FILENO);
	dup2(data->fds[data->fd * 2], STDIN_FILENO);
	close_fd(data->fd_out, data->fds[0], data->fds[1]);
	data->path = get_path(arg, environ);
	data->args = get_args(arg);
	execve(data->path, data->args, environ);
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
