#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pipe
{
  int pipe_fd[2];
}t_pipe;


#endif
