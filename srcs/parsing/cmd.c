/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:22:32 by synicole          #+#    #+#             */
/*   Updated: 2023/05/16 15:23:02 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_cmd	*ft_init_cmd(t_token **current)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->name = (*current)->str;
	cmd->fd_read = 0;
	cmd->fd_write = 1;
	cmd->next = NULL;
	while ((*current) != NULL)
	{
		if ((*current)->type == E_STRING)
			cmd->option = ft_get_cmd_option(current, cmd);
		else if ((*current)->type == E_PIPE)
		{
			(*current) = (*current)->next;
			while (((*current)->type == E_PIPE && (*current) != NULL) ||\
			((*current)->type == E_SPACE && (*current) != NULL))
				(*current) = (*current)->next;
			break ;
		}
		else if ((*current) != NULL)
			(*current) = (*current)->next;
	}
	return (cmd);
}


void	ft_command(t_env *env)
{
	t_token	*start;
	t_token	*current;

	start = env->token;
	current = env->token;
	while (current)
	{
		if (!env->cmd)
			env->cmd = ft_init_cmd(&current);
		else
			ft_add_cmd_end(&env->cmd, ft_init_cmd(&current));
	}
	env->token = start;
}
