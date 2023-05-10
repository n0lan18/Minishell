/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_type_of_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:10:19 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/10 12:02:58 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_type_in_list(t_token *list, t_token *env)
{
	t_token	*tmp;

	tmp = list;
	while (tmp)
	{
		tmp->type = search_which_type(tmp->str, tmp, env);
		tmp = tmp->next;
	}
}

int	search_which_type(char *str, t_token *list, t_token *env)
{
	char	open_file;

	open_file = open(str, O_RDONLY);
	if ((ft_strncmp(str, "echo", 5) == 0)
		|| (ft_strncmp(str, "cd", 3) == 0)
		|| (ft_strncmp(str, "export", 7) == 0)
		|| (ft_strncmp(str, "pwd", 4) == 0)
		|| (ft_strncmp(str, "env", 4) == 0)
		|| (ft_strncmp(str, "unset", 6) == 0)
		|| (ft_strncmp(str, "exit", 5) == 0))
		list->type = BUILTIN;
	else if (ft_strncmp(str, "|", ft_strlen(str)) == 0)
		list->type = PIPE;
	else if (ft_strncmp(str, "'", ft_strlen(str)) == 0)
		list->type = QUOTE;
	else if (str[0] == '"')
		list->type = DQUOTE;
	else if (is_space(str))
		list->type = SPACE;
	else if ((ft_strncmp(str, ">", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "<", ft_strlen(str)) == 0))
		list->type = CHEVRON;
	else if (search_of_type_cmd(env, str) == 0)
		list->type = CMD;
	else if (open_file != -1)
		list->type = FILE_OPEN;
	else
		list->type = DKNOWN;
	return (list->type);
}
