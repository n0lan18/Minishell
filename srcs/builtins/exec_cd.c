/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:14:25 by synicole          #+#    #+#             */
/*   Updated: 2023/04/25 23:14:28 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Executes the cd command.
 * @param t_token *list
 *
 * @return int exit_code
 */
int	ft_exec_cd(t_env *env, char **option)
{
	int		i;

	i = 1;
	if (!option[i])
	{
		if (chdir(ft_get_envp_value_by_name(env->envp, "HOME")))
		{
			perror("minishell: cd: HOME not set");
			return (EXIT_FAILURE);
		}
	}
	else
	{
		if (chdir(option[i]))
		{
			perror(ft_strjoin("minishell: cd: ", option[i]));
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
