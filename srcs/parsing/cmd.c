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

/**
 * Get size of **option.
 *
 * @param option
 *
 * @return int
 */
static int	ft_len_option(char **option)
{
	int	len;

	len = 0;
	while (option[len])
		len++;
	return (len);
}

/**
 * TODO
 *
 * @param option
 * @param option_tmp
 *
 * @return char**
 */
static char	**ft_get_option(char **option, char **option_tmp)
{
	size_t	i;

	i = 0;
	while (option_tmp[i])
	{
		option[i] = ft_strdup(option_tmp[i]);
		i++;
	}
	return (option);
}

/**
 * Get option(s) for the command.
 *
 * @param current
 * @param cmd
 *
 * @return char** options
 */
static char	**ft_get_cmd_option(t_token **current, t_cmd *cmd)
{
	size_t	i;
	char	*option_tmp[1024];
	char	**option;

	i = 1;
	cmd->name = (*current)->str;
	option_tmp[0] = cmd->name;
	(*current) = (*current)->next;
	while ((*current))
	{
		if ((*current)->type == E_PIPE || (*current)->type == E_REDIRECTION)
			break ;
		else if ((*current)->type == E_STRING && (*current)->show)
		{
			option_tmp[i] = (*current)->str;
			i++;
		}
		if ((*current))
			(*current) = (*current)->next;
	}
	option_tmp[i] = NULL;
	option = ft_calloc(sizeof(char *), ft_len_option(option_tmp) + 1);
	option = ft_get_option(option, option_tmp);
	return (option);
}

/**
 * Initializes a new command.
 *
 * @param token
 *
 * @return t_cmd*
 */
static t_cmd	*ft_init_cmd(t_token **token)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->name = NULL;
	cmd->next = NULL;
	cmd->fd_read = 0;
	cmd->fd_write = 1;
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

/**
 * Create command structure with tokens.
 *
 * @param env
 *
 * @return void
 */
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
