/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:19:29 by wschafer          #+#    #+#             */
/*   Updated: 2025/10/05 17:41:18 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/wait.h>
# include <string.h>

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**environ;

	int		fd_in;
	int		fd_out;
	char	*path;
	char	**args;
	int		*fds;
	int		fd;
	pid_t	*cpid;
	pid_t	status;
}	t_data;

int		main(int argc, char **argv, char **environ);
int		command_exec(t_data *data);
int		ft_waitpid(t_data *data);
char	*get_path(char *command, char **environ);
char	**get_pathes(char **environ);
char	**get_args(char *command);
int		open_infile(t_data *data);
int		open_outfile(t_data *data);
int		close_fds(int *fds);
void	exec_left_arg(t_data *data, char *arg);
void	exec_right_arg(t_data *data, char *arg);
void	exec_arg(t_data *data, char *arg);
void	make_pipes(t_data *data);
void	free_and_exit(t_data *data, int exit_code);
void	free_arr(char **arr);

#endif