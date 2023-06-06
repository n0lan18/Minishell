/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:10:16 by synicole          #+#    #+#             */
/*   Updated: 2023/05/30 18:04:11 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * TODO
 * @param list
 *
 * @return char*
 */
static char	*struct_to_char_here_doc(t_dollar *list)
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

/**
 * TODO
 *
 * @param envp
 * @param list
 *
 * @return void
 */
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

/**
 * TODO
 *
 * @param env
 * @param current
 *
 * @return void
 */
static void	ft_replace_dollar(t_env *env, t_token *current)
{
	t_dollar	*list_dollars;

	list_dollars = NULL;
	ft_create_list_dollars(&list_dollars, current->str);
	ft_replace_dollar_correct_value(env->envp, &list_dollars);
	current->str = struct_to_char_here_doc(list_dollars);
}

/**
 * TODO
 *
 * @param env
 * @param token
 *
 * @return void
 */
static void	ft_dollar_in_here_doc(t_env *env, t_token *token)
{
	t_token	*current;

	current = token;
	while (current)
	{
		if (current->type == E_STRING)
			if (ft_contains_dollar(current->str))
				ft_replace_dollar(env, current);
		current = current->next;
	}
}

/**
 * TODO
 *
 * @param env
 * @param line
 *
 * @return void
 */
void	ft_heredoc_dollar(t_env *env, char **line)
{
	(void)env;
	printf("line: %s\n", *line);
}
