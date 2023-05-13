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

/**
 * Checks if the character is allowed in an environment variable name.
 * @param c
 *
 * @return int
 */
static int	ft_valid_identifier(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
		return (1);
	return (0);
}

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
	while (str[i])
	{
		if (!ft_valid_identifier(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Execute the unset command.
 * @param env
 *
 * @return void
 */
void	ft_exec_unset(t_env *env)
{
	t_token	*current;

	current = env->token->next;
	while (current)
	{
		if (current->type != E_SPACE)
		{
			if (!ft_contains_only_valid_identifier(current->str))
			{
				ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
				ft_putstr_fd(current->str, STDERR_FILENO);
				ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
				g_last_exit_code = EXIT_FAILURE;
			}
			ft_remove_envp(&env->envp, current->str);
		}
		current = current->next;
	}
}