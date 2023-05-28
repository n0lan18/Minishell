/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 08:37:48 by synicole          #+#    #+#             */
/*   Updated: 2023/05/27 08:37:49 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_heredoc_getname(int nb)
{
	char	*name;
	char	*heredoc;
	int		i;

	i = 0;
	heredoc = ".heredoc0\0";
	name = ft_calloc(sizeof(char), ft_strlen(".heredoc0") + 1);
	if (!name)
		return (NULL);
	while (heredoc[i])
	{
		name[i] = heredoc[i];
		i++;
	}
	name[i - 1] += nb;
	return (name);
}

int	ft_heredoc_syntax(t_token *token, t_env *env)
{
	token = token->next;
	while (token)
	{
		if (token->type == E_PIPE || token->type == E_REDIRECTION)
			return (ft_heredoc_error(env));
		else if (token->type == E_STRING)
		{
			if (!ft_heredoc_is_valid_eof(token->str))
				return (ft_heredoc_error(env));
			g_last_exit_code = 0;
			return (0);
		}
		token = token->next;
	}
	if (token == NULL)
		return (ft_heredoc_error(env));
	return (0);
}

char	*ft_heredoc_getword(char *word)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	if (!str)
		return (NULL);
	while (word[i])
	{
		str[i] = word[i];
		i++;
	}
	return (str);
}

/**
 * Check if line is equal to eof
 *
 * @param eof
 * @param line
 * @return 1 if line is equal to eof, 0 otherwise
 */
int	ft_heredoc_is_eof(t_token *eof, char *line)
{
	char	*str;

	str = eof->str;
	if (eof->quote == E_SINGLE_QUOTE)
		str = ft_strtrim(eof->str, "\'");
	else if (eof->quote == E_DOUBLE_QUOTE)
		str = ft_strtrim(eof->str, "\"");
	if (ft_strncmp(str, line, ft_strlen(str) + 1) == 0)
		return (1);
	return (0);
}
