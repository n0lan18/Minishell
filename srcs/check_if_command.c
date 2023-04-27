/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:51:27 by synicole          #+#    #+#             */
/*   Updated: 2023/04/27 08:51:30 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	find_cmd_path_ext(char *dir, char *cmd, char **cmd_path)
{
	char	*tmp_path;

	while (dir != NULL)
	{
		tmp_path = malloc(strlen(dir) + strlen(cmd) + 2);
		sprintf(tmp_path, "%s/%s", dir, cmd);
		if (access(tmp_path, X_OK) == 0)
		{
			*cmd_path = tmp_path;
			break ;
		}
		free(tmp_path);
		dir = strtok(NULL, ":");
	}
}

static void	find_cmd_path(char *cmd, char **cmd_path, char **envp)
{
	int		i;
	char	*path;
	char	*path_copy;
	char	*dir;

	i = 0;
	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			path_copy = strdup(path);
			dir = strtok(path_copy, ":");
			find_cmd_path_ext(dir, cmd, cmd_path);
			free(path_copy);
			if (cmd_path != NULL)
				break ;
		}
		i++;
	}
}

static void	child_process(char *cmd, char *cmd_path, char **envp)
{
	char	*args[2];

	args[0] = cmd;
	args[1] = NULL;
	if (cmd_path == NULL)
	{
		printf("minishell: %s: command not found\n", cmd);
		exit(1);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		perror("execve");
		exit(1);
	}
}

static void	parent_process(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
			printf("Failed command with code %d\n", WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
		printf("Failed command by signal %d\n", WTERMSIG(status));
}

void	check_if_command(t_token *list, char **envp)
{
	char	*cmd;
	char	*cmd_path;
	pid_t	pid;

	cmd = list->str;
	cmd_path = NULL;
	find_cmd_path(cmd, &cmd_path, envp);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	else if (pid == 0)
		child_process(cmd, cmd_path, envp);
	else
		parent_process(pid);
}
