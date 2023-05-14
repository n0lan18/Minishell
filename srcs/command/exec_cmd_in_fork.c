/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_in_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:51:28 by synicole          #+#    #+#             */
/*   Updated: 2023/05/14 15:51:30 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_execute_external(t_env *env, t_cmd *cmd)
{
	char	filepath[PATH_MAX];
	char	**splited_path;
	char	**envp;
	int		i;

	envp = ft_envp_to_char(env->envp);
	if (access(cmd->name, X_OK) == 0)
		execve(cmd->name, cmd->option, envp);
	splited_path = ft_get_splited_path(env->envp);
	i = 0;
	while (splited_path && splited_path[i] != NULL)
	{
		ft_strlcpy(filepath, splited_path[i], PATH_MAX);
		ft_strlcat(filepath, "/", PATH_MAX);
		ft_strlcat(filepath, cmd->name, PATH_MAX);
		if (access(filepath, X_OK) == 0)
		{
			execve(filepath, cmd->option, envp);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_print_cmd_not_found(cmd->name);
	exit(127);
}

void	ft_execute_external_in_fork(t_env *env)
{
	pid_t	fork_pid;
	int		exit_status;

	fork_pid = fork();
	if (!fork_pid)
		ft_execute_external(env, env->cmd);
	waitpid(fork_pid, &exit_status, 0);
	if (WIFEXITED(exit_status))
		g_last_exit_code = WEXITSTATUS(exit_status);
}
