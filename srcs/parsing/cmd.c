/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:22:32 by synicole          #+#    #+#             */
/*   Updated: 2023/05/23 12:04:45 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//static void	ft_init_option_in_cmd(t_token **token, t_cmd *cmd)
//{
//	while ((*token))
//	{
//		if ((*token)->type == E_REDIRECTION)
//			ft_open_files_redirection(token, cmd);
//		else if ((*token)->type == E_STRING)
//			cmd->option = ft_get_cmd_option(token, cmd);
//		else if ((*token)->type == E_PIPE)
//		{
//			(*token) = (*token)->next;
//			break ;
//		}
//		else if ((*token))
//			(*token) = (*token)->next;
//	}
//}

static t_cmd	*ft_init_cmd(t_token **token)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->name = (*token)->str;
	cmd->fd_read = 0;
	cmd->fd_write = 1;
	cmd->next = NULL;
//	ft_init_option_in_cmd(token, cmd);
	while ((*token))
	{
		if ((*token)->type == E_REDIRECTION)
			ft_open_files_redirection(token, cmd);
		else if ((*token)->type == E_STRING)
			cmd->option = ft_get_cmd_option(token, cmd);
		else if ((*token)->type == E_PIPE)
		{
			(*token) = (*token)->next;
			break ;
		}
		else if ((*token))
			(*token) = (*token)->next;
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
