/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:49:11 by synicole          #+#    #+#             */
/*   Updated: 2023/05/28 20:49:13 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * TODO
 *
 * @param str
 *
 * @return int
 */
static int	ft_open_failed(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	return (1);
}

/**
 * TODO
 *
 * @param token
 * @return int
 */
static int	ft_get_infile(t_token **token)
{
	int	fd;

	fd = 0;
	(*token) = (*token)->next;
	if ((*token) == NULL)
		return (fd);
	while ((*token)->type == E_SPACE)
	{
		if ((*token)->next == NULL)
		{
			(*token) = (*token)->next;
			break ;
		}
		(*token) = (*token)->next;
	}
	if ((*token) != NULL)
		fd = open((*token)->str, O_RDONLY);
	if (fd == -1)
		g_last_exit_code = ft_open_failed((*token)->str);
	else
		g_last_exit_code = 0;
	return (fd);
}

/**
 * TODO
 *
 * @param **token
 * @return int
 */
static int	ft_get_outfile(t_token **token)
{
	int	fd;

	fd = 1;
	(*token) = (*token)->next;
	if ((*token) == NULL)
		return (fd);
	while ((*token)->type == E_SPACE)
	{
		if ((*token)->next == NULL)
		{
			(*token) = (*token)->next;
			break ;
		}
		(*token) = (*token)->next;
	}
	if ((*token) != NULL)
		fd = open((*token)->str, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	g_last_exit_code = 0;
	return (fd);
}

/**
 * TODO
 *
 * @param **token
 * @return int
 */
static int	ft_get_outfile_append(t_token **token)
{
	int	fd;

	fd = 1;
	(*token) = (*token)->next;
	if ((*token) == NULL)
		return (fd);
	while ((*token)->type == E_SPACE)
	{
		if ((*token)->next == NULL)
		{
			(*token) = (*token)->next;
			break ;
		}
		(*token) = (*token)->next;
	}
	if ((*token) != NULL)
		fd = open((*token)->str, O_APPEND | O_CREAT | O_WRONLY, 0644);
	g_last_exit_code = 0;
	return (fd);
}

/**
 * TODO
 *
 * @param **token
 * @param *cmd
 */
void	ft_open_files_redirection(t_token **token, t_cmd *cmd)
{
	if (ft_strncmp((*token)->str, "<", 2) == 0)
	{
		cmd->fd_read = ft_get_infile(token);
		if ((*token))
			(*token) = (*token)->next;
	}
	else if (ft_strncmp((*token)->str, ">", 2) == 0)
	{
		cmd->fd_write = ft_get_outfile(token);
		if ((*token))
			(*token) = (*token)->next;
	}
	else if (ft_strncmp((*token)->str, ">>", 3) == 0)
	{
		cmd->fd_write = ft_get_outfile_append(token);
		if ((*token))
			(*token) = (*token)->next;
	}
}
