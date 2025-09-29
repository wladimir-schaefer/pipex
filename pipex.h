#ifndef FDF_H
# define FDF_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/wait.h>

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	char	*path;
	char	**args;
	char	*file1;
	char	*file2;
	int		*fds;
	int		fd;
	pid_t	cpid[2];
}	t_data;

int		main(int argc, char **argv, char **environ);
char	*get_path(char *command, char **environ);
char	**get_pathes(char **environ);
char	**get_args(char *command);
int		open_infile(char *file1);
int		open_outfile(char *file2);
int		close_fd(int n, ...);
void	exec_left_arg(t_data *data, char *arg, char **environ);
void	exec_right_arg(t_data *data, char *arg, char **environ);
void	make_pipes(t_data *data, int argc);

#endif