/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:29:29 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/27 11:22:16 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Display the environment variables.
 *
 * @param envp
 *
 * @return void
 */
void	ft_exec_env(t_envp *envp)
{
	t_envp	*current;

	current = envp;
	while (current)
	{
		printf("%s\n", current->line);
		current = current->next;
	}
}
