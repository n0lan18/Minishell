/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:45:38 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/23 12:14:19 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Check the size of cmd in the struct. To know how many pipe we have to create
 * and the stop condition of the while loop.
 * @param env
 * @param cmd
 *
 * @return int
 */
//int	ft_size_of_struct_cmd(t_cmd *cmd)
//{
//	int		i;
//	t_cmd	*tmp;
//
//	i = 0;
//	tmp = cmd;
//	while (tmp)
//	{
//		i++;
//		tmp = tmp->next;
//	}
//	return (i);
//}

/**
 * In the begining of pipe_execution the first cmd is different as other.
 * So it is not in the loop.
 * @param env
 * @param i
 * @param fd
 *
 * @return void
 */
//static void	ft_execute_first_cmd(t_env *env, int i, int **fd)
//{
//	int		status;
//
//	if (!fork())
//	{
//		close(fd[i][0]);
//		dup2(fd[i][1], STDOUT_FILENO);
//		ft_execute_external(env, env->cmd);
//	}
//	else
//	{
//		close(fd[i][1]);
//		wait(&status);
//		if (WIFEXITED(status))
//			g_last_exit_code = WEXITSTATUS(status);
//	}
//}

/**
 * Child in loop close the write of first pipe and send the result in pipe if
 * the is other cmd or to stdout and execute the cmd
 * @param env
 * @param i
 * @param fd
 * @param num_cmd
 *
 * @return void
 */
//static void	ft_child_in_loop(t_env *env, int i, int **fd, int num_cmd)
//{
//	close(fd[i - 1][1]);
//	dup2(fd[i - 1][0], STDIN_FILENO);
//	if (i < num_cmd)
//	{
//		close(fd[i][0]);
//		dup2(fd[i][1], STDOUT_FILENO);
//	}
//	ft_execute_external(env, env->cmd);
//}

/**
 * The parent close the pipe who is open to say to children "have finish".
 * The parent wait the child and if there is an error it write the error
 * with status variable
 * @param i
 * @param fd
 * @param num_cmd
 *
 * @return void
 */
//static void	ft_parent_in_loop(int i, int **fd, int num_cmd)
//{
//	int	status;
//
//	if (i < num_cmd)
//		close(fd[i][1]);
//	wait(&status);
//	if (WIFEXITED(status))
//		g_last_exit_code = WEXITSTATUS(status);
//}

/**
 * The execution begin with the count of cmd, the first pipe is create to send
 * the first cmd to the second.
 * The first cmd is executing and it goes in the loop.
 * We create a new pipe if there is new cmd after.
 * The fork is for executing the cmd and the parent is for non exit.
 * Loop finish when all cmd are passed.
 *
 * @param env
 * @return void
 */
//void	ft_execute_pipe(t_env *env)
//{
//	int			num_cmd;
//	int			i;
//	int			**fd;
//	t_cmd		*sleep;
//	int			yes;
//
//	fd = NULL;
//	sleep = NULL;
//	yes = 0;
//	if (ft_check_if_sleep_cmd(env->cmd))
//	{
//		yes = 1;
//		sleep = ft_init_sleep(env->cmd);
//		env->cmd = ft_skip_until_last_sleep(env->cmd);
//	}
//	num_cmd = ft_size_of_struct_cmd(env->cmd);
//	if (num_cmd <= 1)
//	{
//		if (num_cmd > 0)
//			ft_execute_in_pipe(env, env->cmd);
//		ft_execute_in_pipe(env, sleep);
//	}
//	else
//	{
//		fd = ft_init_fd_for_pipe(fd, num_cmd);
//		i = 1;
//		pipe(fd[i]);
//		ft_execute_first_cmd(env, i, fd);
//		while (i < num_cmd)
//		{
//			env->cmd = env->cmd->next;
//			i++;
//			if (i < num_cmd)
//				pipe(fd[i]);
//			if (!fork())
//				ft_child_in_loop(env, i, fd, num_cmd);
//			else
//				ft_parent_in_loop(i, fd, num_cmd);
//		}
//		if (yes == 1)
//			ft_execute_in_pipe(env, sleep);
//	}
//}
