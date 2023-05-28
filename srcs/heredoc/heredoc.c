/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 08:16:32 by synicole          #+#    #+#             */
/*   Updated: 2023/05/27 08:16:33 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Write the heredoc in the file.
 *
 * @param heredoc
 * @param name
 * @param env
 *
 * @return void
 */
static void	ft_heredoc_write(t_token *eof, char *name, t_env *env)
{
	int		fd_heredoc;
	char	*line;
	char	*new_line;
	char	*all;

	(void) env;
	all = NULL;
	fd_heredoc = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0664);
	line = readline("> ");
	while (line)
	{
		if (ft_heredoc_is_eof(eof, line))
			break ;
		new_line = ft_strjoin(line, "\n");
		free(line);
		all = ft_heredoc_strjoin(all, new_line);
		line = readline("> ");
	}
	if (all)
		ft_putstr_fd(all, fd_heredoc);
	free(line);
	free(all);
	close(fd_heredoc);
}

static void	ft_eof_found(t_token *token, t_token *new, char *name, t_env *env)
{
	t_token	*tmp;

	ft_heredoc_write(token, name, env);
	tmp = token;
	if (token->next)
		ft_add_token_end(&(*new).next, token->next);
	free(tmp->str);
	free(tmp);
}

static t_token	*ft_get_heredoc(t_token *token, t_env *env, int i)
{
	t_token	*new;
	t_token	*tmp;
	char	*name;

	if (ft_heredoc_syntax(token, env) == 1)
		return (token);
	name = ft_heredoc_getname(i);
	new = ft_new_token(ft_heredoc_getword("<"));
	new->previous = token->previous;
	ft_add_token_end(&new, ft_new_token(ft_heredoc_getword(name)));
	while (token)
	{
		if (token->type == E_STRING)
		{
			ft_eof_found(token, new, name, env);
			break ;
		}
		tmp = token;
		token = token->next;
		free(tmp->str);
		free(tmp);
	}
	free(name);
	return (new);
}

static void	ft_heredoc_found(t_token **current, t_env *env)
{
	int		i;

	i = 0;
	if (!(*current)->previous)
	{
		i++;
		(*current) = ft_get_heredoc((*current), env, i);
	}
	else
	{
		i++;
		(*current) = (*current)->previous;
		(*current)->next = ft_get_heredoc((*current)->next, env, i);
	}
	if ((*current)->next)
	{
		if ((*current)->next->redirection == E_HEREDOC)
			(*current) = (*current)->next;
	}
}

/**
 * Check each token for heredoc redirection.
 *
 * @param env
 *
 * @return void
 */
void	ft_heredoc(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
		if (current->redirection == E_HEREDOC && !current->next)
		{
			ft_heredoc_error(env);
			break ;
		}
		if (current->redirection == E_HEREDOC)
			ft_heredoc_found(&current, env);
		if (!current->next)
			break ;
		current = current->next;
	}
	while (current->previous)
		current = current->previous;
	env->token = current;
}
