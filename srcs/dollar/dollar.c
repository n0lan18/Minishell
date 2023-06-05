/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:15:22 by synicole          #+#    #+#             */
/*   Updated: 2023/05/06 22:15:23 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Convert the list of dollar to a string.
 *
 * @param *list
 *
 * @return char*
 */
char	*struct_to_char(t_dollar *list)
{
	t_dollar	*current;
	char		*str;
	char		*tmp;

	current = list;
	while (!current->str)
		current = current->next;
	str = ft_strdup(current->str);
	current = current->next;
	while (current)
	{
		if (current->str)
		{
			tmp = str;
			str = ft_strjoin(str, current->str);
			free(tmp);
		}
		current = current->next;
	}
	return (str);
}

/**
 * Replace each element of the list with the correct value.
 *
 * @param envp
 * @param **list
 *
 * @return void
 */
static void	ft_replace_dollar_correct_value(t_envp *envp, t_dollar **list)
{
	t_dollar	*current;
	char		*trimmed;

	current = *list;
	while (current)
	{
		if (current->str[0] == '$' && current->str[1] == '?')
		{
			free(current->str);
			current->str = ft_itoa(g_last_exit_code);
		}
		else if (current->str[0] == '$' && current->str[1])
		{
			trimmed = ft_strtrim(current->str, "$");
			free(current->str);
			current->str = ft_get_envp_value_by_name(envp, trimmed);
			free(trimmed);
		}
		current = current->next;
	}
}

/**
 * Replace the dollar variables in the given token.
 * 1. Create a dollar list.
 * 2. Replace the value of each element of the list.
 * 3. Convert the list to a string.
 * 4. Free the list.
 *
 * @param env
 * @param current
 *
 * @return void
 */
static void	ft_replace_dollar(t_env *env, t_token *current)
{
	t_dollar	*list_dollars;
	char		*trimmed;

	list_dollars = NULL;
	trimmed = ft_strtrim(current->str, "\"");
	ft_create_list_dollars(&list_dollars, trimmed);
	free(trimmed);
	ft_replace_dollar_correct_value(env->envp, &list_dollars);
	free(current->str);
	current->str = struct_to_char(list_dollars);
	if (!current->str[0])
		current->show = 0;
	ft_free_dollar(list_dollars);
}

/**
 * Parses the tokens and replaces the dollar variables if needed.
 *
 * @param *env
 *
 * @return void
 */
void	ft_dollar(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
		if (current->type == E_STRING && current->quote != E_SINGLE_QUOTE
			&& ft_contains_dollar(current->str))
			ft_replace_dollar(env, current);
		current = current->next;
	}
}
