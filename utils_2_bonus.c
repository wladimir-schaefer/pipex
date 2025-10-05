/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:53:01 by wschafer          #+#    #+#             */
/*   Updated: 2025/10/05 19:12:52 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *command, char **environ)
{
	char	**pathes;
	char	**splitted_command;
	char	*path;
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
		path = ft_strjoin(pathes[i], "/");
		path = ft_strjoin(path, splitted_command[0]);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
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
