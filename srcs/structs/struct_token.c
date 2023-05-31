/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:21:48 by synicole          #+#    #+#             */
/*   Updated: 2023/05/02 16:21:50 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Get the type of the token
 * @param str
 *
 * @return int
 */
static int	ft_get_token_type(const char *str)
{
	if (ft_contains_only_space(str))
		return (E_SPACE);
	else if (ft_is_redirection(str) == 1)
		return (E_REDIRECTION);
	else if (ft_strncmp(str, "|", 2) == 0)
		return (E_PIPE);
	else
		return (E_STRING);
}

/**
 * Get the quote of the token
 * @param str
 *
 * @return int
 */
static int	ft_get_token_quote(const char *str)
{
	if (str[0] == '\'')
		return (E_SINGLE_QUOTE);
	else if (str[0] == '"')
		return (E_DOUBLE_QUOTE);
	return (E_NONE_QUOTE);
}

/**
 * Get the redirection of the token
 * @param str
 *
 * @return int
 */
static int	ft_get_redirection(char *str)
{
	if (ft_strncmp(str, "<", 2) == 0)
		return (E_INFILE);
	else if (ft_strncmp(str, ">", 2) == 0)
		return (E_OUTFILE);
	else if (ft_strncmp(str, "<<", 3) == 0)
		return (E_HEREDOC);
	else if (ft_strncmp(str, ">>", 3) == 0)
		return (E_APPEND);
	return (E_NOREDIRECTION);
}

/**
 * Creates a new token.
 * @param str
 *
 * @return t_token *new
 */
t_token	*ft_new_token(char *str)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->str = ft_strdup(str);
	new->type = ft_get_token_type(str);
	new->quote = ft_get_token_quote(str);
	new->redirection = ft_get_redirection(str);
	new->next = NULL;
	new->previous = NULL;
	new->show = 1;
	return (new);
}

/**
 * Adds a new token at the end of the given list.
 * @param t_token **list the current list of tokens to add to
 * @param t_token *new the new token to add
 *
 * @return void
*/
void	ft_add_token_end(t_token **lst, t_token *new)
{
	t_token	*current;

	current = *lst;
	if (!current)
		return ;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
		new->previous = current;
	}
}
