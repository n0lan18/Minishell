/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:59:44 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/10 12:04:55 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	search_path_in_env(t_token *env)
{
	t_token	*tmp;
	int		j;

	tmp = env;
	j = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->str, "PATH=", 5) == 0)
			break ;
		j++;
		tmp = tmp->next;
	}
	return (j);
}

char	*join_all_path(char *env, char *cmd, char slash)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!env || !cmd)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(env) + ft_strlen(cmd) + slash + 1));
	if (!join)
		return (NULL);
	while (env[i])
		join[j++] = env[i++];
	join[j] = slash;
	j++;
	i = 0;
	while (cmd[i])
		join[j++] = cmd[i++];
	join[j] = '\0';
	return (join);
}

static int	search_of_type_cmd_ext(char **envp, char *tab)
{
	char	*temp;
	int		i;

	i = 0;
	while (envp[i])
	{
		temp = join_all_path(envp[i], tab, '/');
		if (access(temp, X_OK) == 0)
		{
			free(temp);
			free_double_tab(envp);
			return (0);
		}
		free(temp);
		i++;
	}
	free_double_tab(envp);
	return (1);
}

int	search_of_type_cmd(t_token *env, char *tab)
{
	char	*envpi;
	char	**envp;
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (i < search_path_in_env(env))
	{
		tmp = tmp->next;
		i++;
	}
	envpi = &tmp->str[5];
	envp = ft_split(envpi, ':');
	return (search_of_type_cmd_ext(envp, tab));
}
