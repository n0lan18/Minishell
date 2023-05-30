/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:48:35 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/30 16:45:25 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Check if the command is a builtins
 * @param str
 *
 * @return int
 */
int	ft_is_builtins(const char *str)
{
	if (ft_strncmp(str, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "export", 7) == 0)
		return (1);
	else if (ft_strncmp(str, "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(str, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "exit", 5) == 0)
		return (1);
	return (0);
}

/**
 * Execute the builtins
 * @param env
 *
 * @return void
 */
void	ft_execute_builtins(t_env *env)
{
	if (ft_strncmp(env->token->str, "echo", 5) == 0)
		ft_exec_echo(env->token);
	else if (ft_strncmp(env->token->str, "env", 4) == 0)
		ft_exec_env(env->envp);
	else if (ft_strncmp(env->token->str, "export", 7) == 0)
		ft_exec_export(env);
	else if (ft_strncmp(env->token->str, "unset", 6) == 0)
		ft_exec_unset(env);
	else if (ft_strncmp(env->token->str, "pwd", 4) == 0)
		ft_exec_pwd();
	else if (ft_strncmp(env->token->str, "cd", 3) == 0)
		ft_exec_cd(env->token);
	else if (ft_strncmp(env->token->str, "exit", 5) == 0)
		ft_exec_exit();
}
