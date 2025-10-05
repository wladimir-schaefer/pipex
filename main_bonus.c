/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:20:40 by wschafer          #+#    #+#             */
/*   Updated: 2025/10/05 19:35:47 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **environ)
{
	t_data	*data;

	if (argc < 5)
		return (0);
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
			free_and_exit(data, WEXITSTATUS(data->status));
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
