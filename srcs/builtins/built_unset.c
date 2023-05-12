/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:07:04 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/25 18:07:17 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_exec_unset(t_env *env)
{
	t_token	*current;

	current = env->token->next;
	while (current)
	{
		if (current->type != E_SPACE)
			ft_remove_envp(&env->envp, current->str);
		current = current->next;
	}
}
