/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_command_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:45:31 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/03 19:26:10 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_cmd_path_ext(char *dir, char *cmd, char **cmd_path)
{
	char	*tmp_path;

	while (dir != NULL)
	{
		tmp_path = malloc(strlen(dir) + strlen(cmd) + 2);
		sprintf(tmp_path, "%s/%s", dir, cmd);
		if (access(tmp_path, X_OK) == 0)
		{
			*cmd_path = tmp_path;
			break ;
		}
		free(tmp_path);
		dir = strtok(NULL, ":");
	}
}

void	find_cmd_path(char *cmd, char **cmd_path, t_token *env)
{
	char	*path;
	char	*path_copy;
	char	*dir;
	t_token	*tmp;

	tmp = env;
	while (tmp)
	{
		if (strncmp(tmp->str, "PATH=", 5) == 0)
		{
			path = tmp->str + 5;
			path_copy = strdup(path);
			dir = strtok(path_copy, ":");
			find_cmd_path_ext(dir, cmd, cmd_path);
			free(path_copy);
			if (cmd_path != NULL)
				break ;
		}
		tmp = tmp->next;
	}
}
