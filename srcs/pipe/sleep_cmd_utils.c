/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:27:01 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/22 11:29:18 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Fonction who execute every cmd as we want in a fork with *env
 * @param env 
 * @param cmd 
 * 
 * @return void
 */
void	ft_execute_in_pipe(t_env *env, t_cmd *cmd)
{
	pid_t	fork_pid;
	int		exit_status;

	fork_pid = fork();
	if (!fork_pid)
		ft_execute_external(env, cmd);
	waitpid(fork_pid, &exit_status, 0);
	if (WIFEXITED(exit_status))
		g_last_exit_code = WEXITSTATUS(exit_status);
}


char	*ft_search_biggest_timer_in_sleep(t_cmd *cmd)
{
	int		biggest_timer;
	char	*biggest_timer_str;
	t_cmd	*tmp;

	biggest_timer = 0;
	tmp = cmd;
	while (tmp)
	{
		if (ft_check_if_sleep_cmd(tmp))
		{
			if (ft_atoi(tmp->option[1]) > biggest_timer)
			{
				biggest_timer = ft_atoi(tmp->option[1]);
				biggest_timer_str = tmp->option[1];
			}
		}
		tmp = tmp->next;
	}
	return (biggest_timer_str);
}

t_cmd	*ft_search_and_replace_sleep_with_biggest_timer(t_cmd *cmd)
{
	int		i;
	int		last_sleep_cmd_struc_cmd;
	char	*biggest_timer_str;

	biggest_timer_str = ft_search_biggest_timer_in_sleep(cmd);
	i = 0;
	last_sleep_cmd_struc_cmd = ft_search_last_sleep_cmd_struc_cmd(cmd);
	while (i < last_sleep_cmd_struc_cmd - 1)
	{
		i++;
		cmd = cmd->next;
	}
	cmd->option[1] = ft_strdup(biggest_timer_str);
	return (cmd);
}

t_cmd	*ft_init_sleep(t_cmd *cmd)
{
	t_cmd	*sleep_cmd;

	sleep_cmd = malloc(sizeof(t_cmd));
	if (!sleep_cmd)
		return (NULL);
	sleep_cmd->name = ft_strdup("sleep");
	sleep_cmd->option = malloc(sizeof(char *) * 3);
	if (!sleep_cmd->option)
		return (NULL);
	sleep_cmd->option[0] = ft_strdup("sleep");
	sleep_cmd->option[1] = ft_strdup(ft_search_biggest_timer_in_sleep(cmd));
	sleep_cmd->option[2] = NULL;
	sleep_cmd->next = NULL;
	return (sleep_cmd);
}