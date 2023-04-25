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

void	init_type_in_list(t_token *list, t_token *env)
{
	t_token	*tmp;

	tmp = list;
	while (tmp)
	{
		tmp->type = search_which_type(tmp->str, list, env);
		tmp = tmp->next;
	}
}

int	search_which_type(char *str, t_token *list, t_token *env)
{
	if ((ft_strncmp(str, "echo", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "cd", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "export", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "env", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "unset", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "exit", ft_strlen(str)) == 0))
		list->type = BUILTIN;
	else if (ft_strncmp(str, "|", ft_strlen(str)) == 0)
		list->type = PIPE;
	else if (ft_strncmp(str, "'", ft_strlen(str)) == 0)
		list->type = QUOTE;
	else if (str[0] == '"')
		list->type = DQUOTE;
	else if (ft_strncmp(str, " ", ft_strlen(str)) == 0)
		list->type = SPACE;
	else if ((ft_strncmp(str, ">", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "<", ft_strlen(str)) == 0))
		list->type = CHEVRON;
	else if (search_of_type_cmd(env, str) == 0)
		list->type = CMD;
	else
		list->type = DKNOWN;
	return (list->type);
}
