/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 08:16:32 by synicole          #+#    #+#             */
/*   Updated: 2023/05/30 18:05:08 by nleggeri         ###   ########.fr       */
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
		if (ft_contains_dollar(line))
			line = ft_replace_dollar_in_line(env, line);
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

/**
 * TODO
 *
 * @param token
 * @param new
 * @param name
 * @param env
 *
 * @return void
 */
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

/**
 * 1. Check if the EOF is valid. If not, return the token.
 * 2. Create a new token of type "<" and add it to the list.
 * 3. Generate a name for the heredoc file and add it after the "<" token.
 * 4. Loop through the tokens until a string is found (the EOF).
 * 5. Write the heredoc in the file.
 * 6. Return the new token (the "<" token followed by the name of the file).
 *
 * @param token
 * @param env
 * @param version
 *
 * @return t_token* The new token.
 */
static t_token	*ft_get_heredoc(t_token *token, t_env *env, int version)
{
	t_token	*new;
	t_token	*tmp;
	char	*name;

	if (!ft_heredoc_is_valid_eof(env, token))
		return (token);
	new = ft_new_token("<");
	new->previous = token->previous;
	name = ft_heredoc_getname(version);
	ft_add_token_end(&new, ft_new_token(name));
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

/**
 * Check if the current token has previous token or not and call ft_get_heredoc.
 * Also increment the version of the heredoc file.
 *
 * @param current
 * @param env
 * @param version
 *
 * @return void
 */
static void	ft_heredoc_found(t_token **current, t_env *env, int *version)
{
	if (!(*current)->previous)
		(*current) = ft_get_heredoc((*current), env, (*version));
	else
	{
		(*current) = (*current)->previous;
		(*current)->next = ft_get_heredoc((*current)->next, env, (*version));
	}
	(*version)++;
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
	int		version;

	version = 0;
	current = env->token;
	while (current)
	{
		if (current->redirection == E_HEREDOC && !current->next)
		{
			ft_heredoc_error(env);
			break ;
		}
		if (current->redirection == E_HEREDOC)
			ft_heredoc_found(&current, env, &version);
		if (!current->next)
			break ;
		current = current->next;
	}
	while (current->previous)
		current = current->previous;
	env->token = current;
}
