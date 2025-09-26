#ifndef FDF_H
# define FDF_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/wait.h>

int		main(int argc, char **argv, char **environ);
char	*get_path(char *command, char **environ);
char	**get_pathes(char **environ);
char	**get_args(char *command);
int		open_infile(char *file1);
int		open_outfile(char *file2);


#endif