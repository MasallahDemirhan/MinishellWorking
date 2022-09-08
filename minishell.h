#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <errno.h>
#include "Libft/libft.h"
#include <signal.h>

#define PIPE 1
#define COMMAND 2
#define EXEC 3
#define REDIR 4

typedef struct s_redirection
{
	char            *redir;
	char            *args;
	t_redirection   *next;
}   t_redirection;

typedef struct s_command
{
	char            **command;
}   t_command;

typedef struct s_syntax_tree
{
	int				type;
	t_command		*s_command;
	t_redirection	*s_redir;
	t_syntax_tree	*left;
	t_syntax_tree 	*right;
	t_syntax_tree	*prev;
}   t_syntax_tree;

typedef struct s_vars
{
	char    **env;
	char    **export;
	char    *path;
	char    *cmd_path;
	int     ret_signal;
	int     fd[2];
	int		heredoc[2];
	pid_t   *pids;
}   t_vars;

t_vars  g_data;

void    executer(t_syntax_tree *command_line);
void	sig_handler(int sig_num);

char    *get_path(char **env);
char	*get_cmd(char *cmd, t_vars *data);

int	ft_strcmp(char *str1, char *str2);

#endif