/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:20:40 by wschafer          #+#    #+#             */
/*   Updated: 2025/10/03 18:59:41 by wschafer         ###   ########.fr       */
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
		make_pipes(data);
		command_exec(data);
		ft_waitpid(data);
		// printf("Exit code: %d\n", WEXITSTATUS(status));
		close_fds(data->fds);
		free(data->fds);
		free(data);
	}
	return (0);
}

int	command_exec(t_data *data)
{
	int	i;

	data->fd = 0;
	i = 2;
	while ((i - 2) <= (data->argc - 4))
	{
		data->cpid = fork();
		if (data->cpid == -1)
		{
			return (EXIT_FAILURE);
		}
		if (data->cpid == 0)
		{
			if (i == 2)
				exec_left_arg(data, data->argv[i]);
			else if (i == data->argc - 2)
				exec_right_arg(data, data->argv[i]);
			else
				exec_arg(data, data->argv[i]);
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
		waitpid(0, &data->status, 0);
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
		close_fds(data->fds);
		write(2, "Bad file\n", 9);
		exit(1);
	}
	dup2(data->fd_in, STDIN_FILENO);
	dup2(data->fds[data->fd * 2 + 1], STDOUT_FILENO);
	close_fds(data->fds);
	close(data->fd_in);
	data->path = get_path(arg, data->environ);
	data->args = get_args(arg);
	execve(data->path, data->args, data->environ);
}

void	exec_right_arg(t_data *data, char *arg)
{
	data->fd_out = open_outfile(data);
	if (data->fd_out < 0)
	{
		close_fds(data->fds);
		write(2, "Bad file\n", 9);
		exit(1);
	}
	dup2(data->fd_out, STDOUT_FILENO);
	dup2(data->fds[(data->fd - 1) * 2], STDIN_FILENO);
	close_fds(data->fds);
	close(data->fd_out);
	data->path = get_path(arg, data->environ);
	data->args = get_args(arg);
	execve(data->path, data->args, data->environ);
}

void	exec_arg(t_data *data, char *arg)
{
	dup2(data->fds[data->fd * 2 + 1], STDOUT_FILENO);
	dup2(data->fds[(data->fd -1) * 2], STDIN_FILENO);
	close_fds(data->fds);
	data->path = get_path(arg, data->environ);
	data->args = get_args(arg);
	execve(data->path, data->args, data->environ);
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
	int		i;

	pathes = get_pathes(environ);
	if (!pathes)
			return (NULL);;
	splitted_command = ft_split(command, ' ');
	if (!splitted_command)
			return (NULL);;
	i = 0;
	while (pathes[i])
	{
		path = ft_strjoin(pathes[i], "/");
		path = ft_strjoin(path, splitted_command[0]);
		if (access(path, F_OK) == 0)
		{
			free_split(pathes);
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

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}