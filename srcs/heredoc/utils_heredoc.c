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

/**
 * Generate the name of the heredoc file.
 *
 * @param version
 *
 * @return the name of the heredoc file
 */
char	*ft_heredoc_getname(int version)
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
	name[i - 1] += version;
	return (name);
}

/**
 * Check if token is a valid EOF
 *
 * @param env
 * @param token
 *
 * @return 1 if token is valid, 0 otherwise
 */
int	ft_heredoc_is_valid_eof(t_env *env, t_token *token)
{
	token = token->next;
	while (token)
	{
		if (token->type == E_PIPE || token->type == E_REDIRECTION)
		{
			ft_heredoc_error(env);
			return (0);
		}
		else if (token->type == E_STRING)
		{
			if (token->str[0] == '#')
			{
				ft_heredoc_error(env);
				return (0);
			}
			g_last_exit_code = 0;
			return (1);
		}
		token = token->next;
	}
	return (0);
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

/**
 * Custom strjoin for heredoc to join s1 and s2
 *
 * @param s1
 * @param s2
 *
 * @return joined string
 */
char	*ft_heredoc_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*new_str;

	new_str = NULL;
	str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	if (s1 != NULL)
	{
		str = ft_memcpy(str, s1, ft_strlen(s1));
		free(s1);
	}
	new_str = ft_strjoin(str, s2);
	free(str);
	if (s2 != NULL)
		free(s2);
	return (new_str);
}
