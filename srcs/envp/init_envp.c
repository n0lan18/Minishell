/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:31:22 by synicole          #+#    #+#             */
/*   Updated: 2023/05/07 17:31:23 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Initializes the environment variables.
 *
 * @param env pointer to the t_env structure to be initialized
 * @param envp array of strings containing the environment variables
 *
 * @return void
 */
void	ft_init_envp(t_env *env, char **envpchar)
{
	int	i;

	env->envp = ft_new_envp(envpchar[0]);
	i = 1;
	while (envpchar[i])
	{
		ft_add_envp_end(&env->envp, ft_new_envp(envpchar[i]));
		i++;
	}
}
