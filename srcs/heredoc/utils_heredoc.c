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
			if (ft_heredoc_error_eof(token->str) == 1)
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

void	ft_add_previous(t_token *current)
{
	while (current->next)
	{
		current->next->previous = current;
		current = current->next;
	}
	while (current->previous)
		current = current->previous;
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

int	ft_heredoc_strcmp(t_token *heredoc, char *line)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	if (heredoc->quote != E_NONE_QUOTE)
	{
		j = 1;
		len -= 1;
	}
	while (i < len)
	{
		if (heredoc->str[j] != line[i])
			break ;
		j++;
		i++;
	}
	return (heredoc->str[j] - line[i]);
}
