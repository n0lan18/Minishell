/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:09:51 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/26 16:33:23 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Checks if the string contains only valid characters for an environment
 * variable name.
 * @param str
 *
 * @return int
 */
static int	ft_contains_only_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_valid_identifier(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Execute the export command.
 * @param env
 *
 * @return void
 */
void	ft_exec_export(t_env *env)
{
	t_token	*current;
	t_envp	*envp;

	current = env->token->next;
	while (current)
	{
		if (current->type != E_SPACE)
		{
			if (!ft_contains_only_valid_identifier(current->str))
			{
				ft_putstr_fd("minishell: export: `", STDERR_FILENO);
				ft_putstr_fd(current->str, STDERR_FILENO);
				ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
				g_last_exit_code = EXIT_FAILURE;
			}
			else if (ft_strchr(current->str, '='))
			{
				envp = ft_new_envp(current->str);
				ft_add_envp_end(&env->envp, envp);
			}
		}
		current = current->next;
	}
}
