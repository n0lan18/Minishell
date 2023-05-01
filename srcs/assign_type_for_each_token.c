/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_type_of_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:10:19 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/16 23:10:39 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	ft_assign_type_for_each_token(t_token *list)
{
	while (list)
	{
		if (ft_is_builtin(list->str))
			list->type = BUILTIN;
		else if (list->str[0] == '|')
			list->type = PIPE;
		else if (ft_strncmp(list->str, "'", 2) == 0)
			list->type = QUOTE;
		else if (list->str[0] == '"')
			list->type = DQUOTE;
		else if (is_space(list->str))
			list->type = SPACE;
		else if (list->str[0] == '>' || list->str[0] == '<')
			list->type = CHEVRON;
		else
			list->type = DKNOWN;
		list = list->next;
	}
}
