/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:42:21 by synicole          #+#    #+#             */
/*   Updated: 2023/05/30 20:42:22 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Free the envp list from the given environment.
 *
 * @param env
 *
 * @return void
 */
void	ft_free_envp(t_env *env)
{
	t_envp	*tmp;

	while (env->envp)
	{
		tmp = env->envp;
		env->envp = env->envp->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp->line);
		free(tmp);
	}
}
