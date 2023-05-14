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

char	*struct_to_char(t_dollar *list)
{
	t_dollar	*current;
	char		*str;

	current = list;
	while (!current->str)
		current = current->next;
	str = current->str;
	current = current->next;
	while (current)
	{
		if (current->str)
			str = ft_strjoin(str, current->str);
		current = current->next;
	}
	return (str);
}

static void	ft_replace_dollar_correct_value(t_envp *envp, t_dollar **list)
{
	t_dollar	*current;

	current = *list;
	while (current)
	{
		if (current->str[0] == '$' && current->str[1] == '?')
			current->str = ft_itoa(g_last_exit_code);
		else if (current->str[0] == '$' && current->str[1])
			current->str = ft_get_envp_value_by_name(
					envp, ft_strtrim(current->str, "$"));
		current = current->next;
	}
}

static void	ft_replace_dollar(t_env *env, t_token *current)
{
	t_dollar	*list_dollars;

	list_dollars = NULL;
	ft_create_list_dollars(&list_dollars, ft_strtrim(current->str, "\""), 0);
	ft_replace_dollar_correct_value(env->envp, &list_dollars);
	current->str = struct_to_char(list_dollars);
}

void	ft_dollar(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
		if (current->type == E_STRING && current->quote != E_SINGLE_QUOTE)
			if (ft_contains_dollar(current->str))
				ft_replace_dollar(env, current);
		current = current->next;
	}
}
