/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:31:24 by synicole          #+#    #+#             */
/*   Updated: 2023/05/06 21:31:26 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Initializes the environment variables.
 * (t_env){} : initializes all the fields to 0.
 *
 * @param env pointer to the t_env structure to be initialized
 * @param envp array of strings containing the environment variables
 */
void	ft_init_env(t_env *env, char **envp)
{
	(void)envp;
	*env = (t_env){};
	env->envp = envp;
	g_last_exit_code = EXIT_SUCCESS;
}
