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

static void	ft_execute_cmd(t_env *env)
{
	if (ft_is_builtins(env->token->str))
		ft_execute_builtins(env);
	else
		ft_execute_external_in_fork(env);
}

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
