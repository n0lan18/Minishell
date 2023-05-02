/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_type_for_each_token.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:10:19 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/16 23:10:39 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Checks if a given string represents a built-in shell command.
 * @param const char *str The string to check.
 *
 * @return int Returns 1 if it's a built-in command, otherwise 0.
*/
static int	ft_is_builtin(const char *str)
{
	if ((ft_strncmp(str, "echo", 5) == 0)
		|| (ft_strncmp(str, "cd", 3) == 0)
		|| (ft_strncmp(str, "export", 7) == 0)
		|| (ft_strncmp(str, "pwd", 4) == 0)
		|| (ft_strncmp(str, "env", 4) == 0)
		|| (ft_strncmp(str, "unset", 6) == 0)
		|| (ft_strncmp(str, "exit", 5) == 0))
		return (1);
	return (0);
}

/**
 * Assigns a type to each token based on the token's value.
 * @param t_token *list The token list to iterate over.
 *
 * @return void
*/
void	ft_assign_type_for_each_token(t_token *list)
{
	while (list)
	{
		if (ft_is_builtin(list->str))
			list->type = T_BUILTIN;
		else if (list->str[0] == '|')
			list->type = T_PIPE;
		else if (ft_strncmp(list->str, "'", 2) == 0)
			list->type = T_QUOTE;
		else if (list->str[0] == '"')
			list->type = T_DQUOTE;
		else if (ft_contains_only_space(list->str))
			list->type = T_SPACE;
		else if (list->str[0] == '>' || list->str[0] == '<')
			list->type = T_CHEVRON;
		else if (list->str[0] == '$' && list->str[1] == '?')
			list->type = T_EXIT_CODE;
		else if (list->str[0] == '$' && list->str[1] != '?')
			list->type = T_DOLLAR;
		else
			list->type = T_DKNOWN;
		list = list->next;
	}
}
