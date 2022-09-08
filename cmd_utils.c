#include "minishell.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

char	*get_cmd(char *cmd, t_vars *data)
{
	char	*command;
	char	**path_list;
	int		i;

	i = -1;
	path_list = ft_split(data->path, ':');
	while (path_list[++i])
	{
		command = ft_strjoin(path_list[i], cmd, '/');
		if ((access(command, X_OK) == 0))
			return (command);
		free(command);
	}
	return (NULL);
}

char	*get_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (env[i][0] == 'P' && env[i][2] == 'T')
			return (env[i]);
	return (0);
}

/* void	child_process(t_pipex pipex, char **av, char **envp)
{
	int	a;

	a = dup2(pipex.infile, 0);
	if (a == -1)
		sys_call_errors(7);
	a = dup2(pipex.pipe_fd[1], 1);
	if (a == -1)
		sys_call_errors(7);
	a = close(pipex.pipe_fd[0]);
	if (a == -1)
		sys_call_errors(5);
	pipex.cmd_list = ft_split(av[2], ' ');
	pipex.cmd = get_cmd(pipex, pipex.cmd_list[0], envp);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		input_errors(6);
	}
	a = execve(pipex.cmd, pipex.cmd_list, envp);
	if (a == -1)
		input_errors(8);
}

void	child_process2(t_pipex pipex, char **av, char **envp)
{
	int	a;

	a = dup2(pipex.pipe_fd[0], 0);
	if (a == -1)
		sys_call_errors(7);
	a = close(pipex.pipe_fd[1]);
	if (a == -1)
		sys_call_errors(5);
	a = dup2(pipex.outfile, 1);
	if (a == -1)
		sys_call_errors(7);
	pipex.cmd_list = ft_split(av[3], ' ');
	pipex.cmd = get_cmd(pipex, pipex.cmd_list[0], envp);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		input_errors(6);
	}
	a = execve(pipex.cmd, pipex.cmd_list, envp);
	if (a == -1)
		input_errors(8);
}
 */