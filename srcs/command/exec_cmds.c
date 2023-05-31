/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:05:33 by synicole          #+#    #+#             */
/*   Updated: 2023/05/29 21:05:35 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * TODO
 *
 * @param t_env *env
 * @param t_cmd *cmd
 *
 * @return void
 */
void	ft_run_cmd(t_env *env, t_cmd *cmd)
{
	if (!ft_is_builtins(cmd->name))
		ft_execute_external(env, cmd);
	ft_execute_builtins(env, cmd);
	exit(0);
}

/**
 * TODO
 *
 * @param t_env *env
 * @param t_cmd *cmd
 *
 * @return void
 */
void	ft_prepare_fds(t_cmd *cmd, const int *fd_pipe_read_tmp, int *fd_pipe)
{
	close(fd_pipe[0]);
	if (cmd->fd_read == 0)
		cmd->fd_read = *fd_pipe_read_tmp;
	dup2(cmd->fd_read, 0);
	if (cmd->fd_write >= 3)
		close(fd_pipe[1]);
	else if (!cmd->next)
		cmd->fd_write = 1;
	else
		cmd->fd_write = fd_pipe[1];
	dup2(cmd->fd_write, 1);
}

/**
 * TODO
 *
 * @param t_cmd *cmd
 * @param int *fd_pipe_read_tmp
 * @param int *fd_pipe
 *
 * @return void
 */
void	ft_close_fds(t_cmd *cmd, int *fd_pipe_read_tmp, int *fd_pipe)
{
	close(fd_pipe[1]);
	if (*fd_pipe_read_tmp >= 3)
		close(*fd_pipe_read_tmp);
	if (cmd->fd_write >= 3)
		close(cmd->fd_write);
	if (cmd->fd_read >= 3)
		close(cmd->fd_read);
	*fd_pipe_read_tmp = fd_pipe[0];
}

/**
 * TODO
 *
 * @param int exit_status
 *
 * @return void
 */
void	ft_handle_exit_status(int exit_status)
{
	if (WIFEXITED(exit_status))
		g_last_exit_code = WEXITSTATUS(exit_status);
}
