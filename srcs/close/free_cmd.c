/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:01:34 by synicole          #+#    #+#             */
/*   Updated: 2023/05/14 19:01:36 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_free_option(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/**
 * Frees the command list from the given environment.
 *
 * @param t_env *env
 *
 * @return void
*/
void	ft_free_cmd(t_env *env)
{
	t_cmd	*tmp;

	if (!env->cmd || !env->cmd->name)
		return ;
	while (env->cmd)
	{
		tmp = env->cmd;
		ft_free_option(tmp->option);
		env->cmd = env->cmd->next;
		free(tmp);
	}
}
