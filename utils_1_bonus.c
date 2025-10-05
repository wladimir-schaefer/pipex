/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:53:05 by wschafer          #+#    #+#             */
/*   Updated: 2025/10/05 19:24:08 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
		free_and_exit(data, 0);
	}
	data->args = get_args(arg);
	execve(data->path, data->args, data->environ);
	free_and_exit(data, 0);
}

void	exec_right_arg(t_data *data, char *arg)
{
	data->fd_out = open_outfile(data);
	if (data->fd_out < 0)
	{
		perror(data->argv[data->argc - 1]);
		free_and_exit(data, 1);
	}
	dup2(data->fd_out, STDOUT_FILENO);
	dup2(data->fds[(data->fd - 1) * 2], STDIN_FILENO);
	close_fds(data->fds);
	close(data->fd_out);
	data->path = get_path(arg, data->environ);
	if (!data->path)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
		free_and_exit(data, 127);
	}
	data->args = get_args(arg);
	execve(data->path, data->args, data->environ);
	free_and_exit(data, 0);
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
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
		free_and_exit(data, 0);
	}
	execve(data->path, data->args, data->environ);
	free_and_exit(data, 0);
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
