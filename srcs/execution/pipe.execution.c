/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:45:38 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/17 00:48:43 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Check if there is a pipe in the structure.
 * @param env
 * @param cmd
 *
 * @return void
 */
int	check_if_there_is_pipe(t_env *env)
{
	t_token	*tmp;

	tmp = env->token;
	while (tmp)
	{
		if (tmp->type == E_PIPE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/**
 * Check the size of cmd in the struct. To know how many pipe we have to create
 * and the stop condition of the while loop.
 * @param env
 * @param cmd
 *
 * @return int
 */
int	size_of_struct_cmd(t_cmd *cmd)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = cmd;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_execute_pipe(t_env *env)
{
	int	status;
	int	i;
	int	num_cmd;
	int	fd[size_of_struct_cmd(env->cmd)][2];

//	db_print_token(env->token);
	num_cmd = size_of_struct_cmd(env->cmd);
	i = 1;
	pipe(fd[i]);
	if (!fork())
	{
		close(fd[i][0]);
		dup2(fd[i][1], STDOUT_FILENO);
		ft_execute_external(env, env->cmd);
	}
	else
	{
		close(fd[i][1]);
		wait(&status);
		if (WIFEXITED(status))
					g_last_exit_code = WEXITSTATUS(status);
	}
	while (i < num_cmd)
	{
		env->cmd = env->cmd->next;
		i++;
		if (i <= num_cmd)
			pipe(fd[i]);
		if (!fork())
		{
			close(fd[i - 1][1]);
			dup2(fd[i - 1][0], STDIN_FILENO);
			if (i < num_cmd)
			{
				close(fd[i][0]);
				dup2(fd[i][1], STDOUT_FILENO);
			}
			ft_execute_external(env, env->cmd);
		}
		else
		{
			if (i < num_cmd)
				close(fd[i][1]);
			wait(&status);
			if (WIFEXITED(status))
				g_last_exit_code = WEXITSTATUS(status);
		}
	}
}
