/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:58:20 by synicole          #+#    #+#             */
/*   Updated: 2023/05/24 16:57:41 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Executes a builtins command or an external command in a fork.
 * @param env
 */
static void	ft_execute_cmd(t_env *env)
{
	if (ft_is_builtins(env->token->str))
		ft_execute_builtins(env);
	else
		ft_execute_external_in_fork(env);
}

/**
 * Chooses which function to execute depending if there is one or more commands.
 * @param env
 *
 * @return void
 */
void	ft_execute(t_env *env)
{
	if (env->cmd)
	{
		if (!env->cmd->next)
			ft_execute_cmd(env);
		else
			printf("ft_execute_cmds(env);\n");
	}
}
