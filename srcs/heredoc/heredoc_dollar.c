/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:10:16 by synicole          #+#    #+#             */
/*   Updated: 2023/05/27 09:10:17 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_heredoc_strcat_expand(char *s1, char *s2, size_t *i, size_t *j)
{
	s1[(*j)] = s2[(*i)];
	(*i)++;
	(*j)++;
}

static void	ft_heredoc_put_nw(char *var_env, char *nw, size_t *i, size_t *j)
{
	size_t	save;

	save = (*i) + 1;
	(*i) = 0;
	if (var_env != NULL)
	{
		while (var_env[(*i)] != '\0')
			ft_heredoc_strcat_expand(nw, var_env, i, j);
	}
	(*i) = save;
	(*i)++;
}

static int	ft_heredoc_len_new_word(const char *word, char **var_env, int i)
{
	int	count;
	int	j;

	j = 0;
	count = 0;
	while (word[i] != '\0')
	{
		if (word[i] == '$')
		{
			if (var_env[j] != NULL)
				count += (int)ft_strlen(var_env[j]);
			j++;
			i++;
			while (word[i] != '"' && word[i] != ' ' && word[i] != '$'
				&& word[i] != '\0' && word[i] != '\n')
				i++;
		}
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

static char	*ft_heredoc_get_new_word(char *word, char **var_env, size_t i)
{
	char	*new_word;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	new_word = ft_calloc(
			sizeof(char), ft_heredoc_len_new_word(word, var_env, 0) + 1);
	if (!new_word)
		return (NULL);
	while (word[i] != '\0')
	{
		if (word[i] == '$')
		{
			ft_heredoc_put_nw(var_env[k], new_word, &i, &j);
			k++;
			while (word[i] != '"' && word[i] != ' ' && word[i] != '$'
				&& word[i] != '\0' && word[i] != '\n')
				i++;
		}
		else
			ft_heredoc_strcat_expand(new_word, word, &i, &j);
	}
	free(word);
	return (new_word);
}

void	ft_heredoc_replace_varenv(char **str, t_envp *envp)
{
	size_t	i;
	size_t	nb_venv;
	char	*name_venv;
	char	**var_env;

	var_env = ft_calloc(sizeof(char *), ft_nbr_var_envp((*str)) + 1);
	if (!var_env)
		exit(printf("Malloc Error\n") + 247);
	i = 0;
	nb_venv = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '$')
		{
			name_venv = ft_get_envp_name(&(*str)[++i]);
			var_env[nb_venv++] = ft_get_envp_value_by_name(envp, name_venv);
			if (var_env[nb_venv - 1] == NULL)
				break ;
			free(name_venv);
		}
		else
			i++;
	}
	(*str) = ft_heredoc_get_new_word((*str), var_env, 0);
	free(var_env);
}
