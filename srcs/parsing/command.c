/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:22:32 by synicole          #+#    #+#             */
/*   Updated: 2023/05/14 17:22:34 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_command(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
//		if (!env->cmd)
//			env->cmd = ft_new_envp(current);
//		else
//			ft_add_cmd_end(&env->cmd, ft_lstnew_cmd(ft_init_cmd(&pars)));
		current = current->next;
	}
}
