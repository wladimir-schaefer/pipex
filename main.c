/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:20:40 by wschafer          #+#    #+#             */
/*   Updated: 2025/10/05 17:45:00 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **environ)
{
	t_data	*data;

	if (argc < 5)
		return (127);
	else
	{
		data = ft_calloc(1, sizeof(t_data));
		if (!data)
			return (1);
		data->argc = argc;
		data->argv = argv;
		data->environ = environ;
		data->fd = 0;
		make_pipes(data);
		command_exec(data);
		ft_waitpid(data);
		close_fds(data->fds);
		free_arr(data->args);
		free(data->path);
		free(data->fds);
		free(data->cpid);
		free(data);
	}
	return (0);
}

int	command_exec(t_data *data)
{
	int	i;

	i = 0;
	data->cpid = ft_calloc((data->argc - 3), sizeof(pid_t));
	if (!data->fds)
		return (0);
	while (i <= data->argc - 4)
	{
		data->cpid[i] = fork();
		if (data->cpid[i] == -1)
			return (EXIT_FAILURE);
		if (data->cpid[i] == 0)
		{
			if (i + 2 == 2)
				exec_left_arg(data, data->argv[i + 2]);
			else if (i + 2 == data->argc - 2)
				exec_right_arg(data, data->argv[i + 2]);
			else
				exec_arg(data, data->argv[i + 2]);
		}
		i++;
		data->fd++;
	}
	close_fds(data->fds);
	return (0);
}

int	ft_waitpid(t_data *data)
{
	int	i;

	data->status = 0;
	i = 0;
	while (i < data->argc - 3)
	{
		waitpid(data->cpid[i], &data->status, 0);
		if (WIFEXITED(data->status) && WEXITSTATUS(data->status) != 0)
		{
			free_and_exit(data, WEXITSTATUS(data->status));
		}
		i++;
	}
	return (0);
}

void	make_pipes(t_data *data)
{
	int	i;

	data->fds = ft_calloc((data->argc - 4) * 2 + 1, sizeof(int));
	if (!data->fds)
		return ;
	i = 0;
	while (i < data->argc - 4)
	{
		pipe(&data->fds[i * 2]);
		i++;
	}
}

void	exec_left_arg(t_data *data, char *arg)
{
	data->fd_in = open_infile(data);
	if (data->fd_in < 0)
	{
		perror(data->argv[1]);
		free_and_exit(data, 0);
	}
	dup2(data->fd_in, STDIN_FILENO);
	dup2(data->fds[data->fd * 2 + 1], STDOUT_FILENO);
	close_fds(data->fds);
	close(data->fd_in);
	data->path = get_path(arg, data->environ);
	if (!data->path)
	{
		close_fds(data->fds);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
		free_and_exit(data, 0);
	}
	data->args = get_args(arg);
	execve(data->path, data->args, data->environ);
	free_and_exit(data, 0);
	// free_arr(data->args);
	// free(data->path);
	// free(data->fds);
	// free(data->cpid);
	// free(data);
}

void	exec_right_arg(t_data *data, char *arg)
{
	data->fd_out = open_outfile(data);
	if (data->fd_out < 0)
	{
		perror(data->argv[data->argc - 1]);
		// ft_putstr_fd(data->argv[data->argc - 1], 2);
		// ft_putstr_fd(": Permission denied\n", 2);
		free_and_exit(data, 1);
		// free(data->fds);
		// free(data->cpid);
		// free(data);
		// exit(1);
	}
	dup2(data->fd_out, STDOUT_FILENO);
	dup2(data->fds[(data->fd - 1) * 2], STDIN_FILENO);
	close_fds(data->fds);
	close(data->fd_out);
	data->path = get_path(arg, data->environ);
	if (!data->path)
	{
		close_fds(data->fds);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
		free_and_exit(data, 127);
		// free(data->path);
		// free(data->fds);
		// free(data->cpid);
		// free(data);
		// exit(127);
	}
	data->args = get_args(arg);
	execve(data->path, data->args, data->environ);
	free_and_exit(data, 0);
	// free_arr(data->args);
	// free(data->path);
	// free(data->fds);
	// free(data->cpid);
	// free(data);
}

void	exec_arg(t_data *data, char *arg)
{
	dup2(data->fds[data->fd * 2 + 1], STDOUT_FILENO);
	dup2(data->fds[(data->fd -1) * 2], STDIN_FILENO);
	close_fds(data->fds);
	data->path = get_path(arg, data->environ);
	data->args = get_args(arg);
	if (!data->path)
	{
		close_fds(data->fds);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
		free_and_exit(data, 127);
		// free_arr(data->args);
		// free(data->path);
		// free(data->fds);
		// free(data->cpid);
		// free(data);
		// exit(127);
	}
	execve(data->path, data->args, data->environ);
	free_and_exit(data, 0);
	// free_arr(data->args);
	// free(data->path);
	// free(data->fds);
	// free(data->cpid);
	// free(data);
}

int	open_infile(t_data *data)
{
	int	fd;

	fd = open(data->argv[1], O_RDONLY);
	return (fd);
}

int	open_outfile(t_data *data)
{
	int	fd;

	fd = open(data->argv[data->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (fd);
}

char	*get_path(char *command, char **environ)
{
	char	**pathes;
	char	**splitted_command;
	char	*path;
	char	*path1;
	int		i;

	pathes = get_pathes(environ);
	if (!pathes)
		return (NULL);
	splitted_command = ft_split(command, ' ');
	if (!splitted_command)
		return (NULL);
	i = 0;
	while (pathes[i])
	{
		path1 = ft_strjoin(pathes[i], "/");
		path = ft_strjoin(path1, splitted_command[0]);
		if (access(path, X_OK) == 0)
		{
			free_arr(pathes);
			free(path1);
			free_arr(splitted_command);
			return (path);
		}
		free(path);
		free(path1);
		i++;
	}
	free_arr(pathes);
	free_arr(splitted_command);
	return (NULL);
}

char	**get_args(char *command)
{
	char	**args;

	args = ft_split(command, ' ');
	if (!args)
		return (NULL);
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
			if (!pathes)
				return (NULL);
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

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void	free_and_exit(t_data *data, int exit_code)
{
	if (data->args)
		free_arr(data->args);
	if (data->path)
		free(data->path);
	if (data->fds)
		free(data->fds);
	if (data->cpid)
		free(data->cpid);
	if (data)
		free(data);
	exit(exit_code);
}
