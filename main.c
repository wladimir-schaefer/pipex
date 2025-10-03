#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **environ)
{
	t_data	*data;

	if (argc < 5)
	{
		ft_printf("Wrong number of arguments\n");
		return(0);
	}
	else
	{
		data = ft_calloc(1, sizeof(t_data));
		if (!data)
			// 	error ();
		data->argc = argc;
		data->argv = argv;
		data->environ = environ;
		data->fd = 0;
		data->file1 = argv[1];
		data->file2 = argv[argc - 1];
		command_exec(data);
		ft_waitpid(data);
		// printf("Exit code: %d\n", WEXITSTATUS(status));
		// close_fds(data->fds);
		// close(data->file1);
		// close(data->file2);
	}
	return(0);
}

int	command_exec(t_data *data)
{
	int	arg;

	arg = 2;
	make_pipes(data);
	while ((arg - 2) <= (data->argc - 4))
	{
		data->cpid = fork();
		// if (data->cpid == -1)
		// 	{
		// 		return (EXIT_FAILURE);
		// 	}
		if (data->cpid == 0 && arg == 2)
			exec_left_arg(data, data->argv[arg], data->environ);
		else if (data->cpid == 0 && arg == data->argc - 2)
			exec_right_arg(data, data->argv[arg], data->environ);
		else if (data->cpid == 0)
			exec_arg(data, data->argv[arg], data->environ);
		arg++;
		data->fd++;
	}
	// close_fds(data->fds);
	return(0);
}

int	ft_waitpid(t_data *data)
{
	// int	i;

	// data->status = 0;
	// i = 0;
	// while (i < data->argc - 3)
	// {
	// 	waitpid(0, &data->status, 0);
	// 	i++;
	// }
	for (int i = 0; i < data->argc - 3; i++) {
		// waitpid(0, &data->status, 0);
		wait(NULL);
	}
	return(0);
}

void	make_pipes(t_data *data)
{
	int	i;

	data->fds = ft_calloc((data->argc - 4) * 2 + 1, sizeof(int));
	// if (!data->fds)
	// 	error();
	i = 0;
	while (i < data->argc - 4)
	{
		pipe(&data->fds[i * 2]);
		i++;
	}
	// i++;
	// data->fds[i] = 0;
	for (int n = 0; n < (data->argc - 4) * 2 + 1; n++)
		printf("fd[%d] = %d\n", n, data->fds[n]);
}

void	exec_left_arg(t_data *data, char *arg, char **environ)
{
	data->fd_in = open_infile(data->file1);
	if (data->fd_in < 0) {
		close_fds(data->fds);
		write(2, "Bad file\n", 9);
		exit(1);
	}
	printf("fd_in = %d\n", data->fd_in);
	dup2(data->fd_in, STDIN_FILENO);
	dup2(data->fds[data->fd * 2 + 1], STDOUT_FILENO);
	close_fds(data->fds);
	close(data->fd_in);
	data->path = get_path(arg, environ);
	data->args = get_args(arg);
	execve(data->path, data->args, environ);
}

void	exec_right_arg(t_data *data, char *arg, char **environ)
{
	data->fd_out = open_outfile(data->file2);
		if (data->fd_out < 0) {
		close_fds(data->fds);
		write(2, "Bad file\n", 9);
		exit(1);
	}
	printf("fd_out = %d\n", data->fd_out);
	dup2(data->fd_out, STDOUT_FILENO);
	dup2(data->fds[(data->fd - 1) * 2], STDIN_FILENO);
	close_fds(data->fds);
	close(data->fd_out);
	data->path = get_path(arg, environ);
	data->args = get_args(arg);
	execve(data->path, data->args, environ);
}

void	exec_arg(t_data *data, char *arg, char **environ)
{
	dup2(data->fds[data->fd * 2 + 1], STDOUT_FILENO);
	dup2(data->fds[(data->fd -1) * 2], STDIN_FILENO);
	close_fds(data->fds);
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

int	close_fds(int *fds)
{
	int	i;
	int	res;

	i = 0;
	while (fds[i])
	{
		res = close(fds[i]);
		if (res != 0)
			return (res);
		i++;
	}
	return (0);
}
