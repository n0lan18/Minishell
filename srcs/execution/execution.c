/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:58:20 by synicole          #+#    #+#             */
/*   Updated: 2023/05/12 10:58:22 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Executes a builtins command or an external command in a fork.
 * @param env
 */
static void	ft_execute_cmd(t_env *env)
{
	int		original_stdin;
	int		original_stdout;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	if (env->cmd->fd_read >= 3)
		dup2(env->cmd->fd_read, STDIN_FILENO);
	if (env->cmd->fd_write >= 3)
		dup2(env->cmd->fd_write, STDOUT_FILENO);
	if (ft_is_builtins(env->cmd->name))
		ft_execute_builtins(env, env->cmd);
	else
		ft_execute_external_in_fork(env);
	if (env->cmd->fd_read >= 3)
		close(env->cmd->fd_read);
	if (env->cmd->fd_write >= 3)
		close(env->cmd->fd_write);
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	close(original_stdin);
}

/**
 * TODO
 *
 * @param env
 *
 * @return void
 */
static void	ft_execute_cmds(t_env *env)
{
	t_cmd	*cmd;
	int		fd_pipe_read_tmp;
	int		fd_pipe[2];
	int		exit_status;
	pid_t	fork_pid;

	cmd = env->cmd;
	fd_pipe_read_tmp = 0;
	while (cmd)
	{
		pipe(fd_pipe);
		fork_pid = fork();
		if (fork_pid == 0)
		{
			ft_prepare_fds(cmd, &fd_pipe_read_tmp, fd_pipe);
			ft_run_cmd(env, cmd);
		}
		ft_close_fds(cmd, &fd_pipe_read_tmp, fd_pipe);
		cmd = cmd->next;
	}
	while (waitpid(-1, &exit_status, 0) > 0)
		;
	ft_handle_exit_status(exit_status);
}

/**
 * Chooses which function to execute depending if there is one or more commands.
 * @param env
 *
 * @return void
 */
void	ft_execute(t_env *env)
{
	if (env->syntax_error_type)
		return ;
	if (env->cmd->name)
	{
		if (!env->cmd->next)
			ft_execute_cmd(env);
		else
			ft_execute_cmds(env);
	}
}
