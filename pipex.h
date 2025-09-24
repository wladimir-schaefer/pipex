#ifndef FDF_H
# define FDF_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int		main(int argc, char **argv, char **environ);
int		check_command(char *command, char **environ);
char	**get_pathes(char **environ);



#endif