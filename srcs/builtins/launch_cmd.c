/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:24:44 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/11 19:33:54 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
/**
 * This fonction search in the list if the first element is a cmd or not
 * @param env
 * 
 * @return int
 */
int	check_if_cmd_first(t_env env)
{
	if (env.token->type == E_CMD)
		return (1);
	return (0);
}

/**
 * Calcule how many size is the char **tab with E_CMD and E_SPACE and E_STRING
 * @param token
 * 
 * @return int
 */
static	int	size_of_char_for_cmd_options(t_token *token)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = token;
	while (tmp)
	{
		if (tmp->type == E_CMD || tmp->str[0] == '-' || tmp->type == E_SPACE)
		{
			if (tmp->type != E_SPACE)
				i++;
			tmp = tmp->next;
		}
		else
			break ;
	}
	return (i);
}

/**
 * This fonction create an array with cmd and options for execve
 * @param token
 * 
 * @return char**
 */
static	char	**tab_with_cmd_and_options(t_token *token)
{
	t_token	*tmp;
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (size_of_char_for_cmd_options(token) + 1));
	if (!tab)
		return (NULL);
	tmp = token;
	while (i < size_of_char_for_cmd_options(token))
	{
		if (tmp->type == E_CMD || tmp->str[0] == '-')
			tab[i++] = ft_strdup(tmp->str);
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}

static	char	**ft_create_path_for_execve(t_envp *env, char *cmd)
{
	t_envp	*tmp;
	char	*env_path;
	char	**envp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp && ft_strncmp(tmp->name, "PATH", 4) != 0)
		tmp = tmp->next;
	env_path = ft_strdup(tmp->value);
	envp = ft_split(env_path, ':');
	while (envp[i])
	{
		envp[i] = join_all_path(envp[i], cmd, '/');
		i++;
	}
	return (envp);
}

static	int	search_e_file_in_list(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == E_FILE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	launch_cmd_if_file_in_list(t_token *tmp, char **path, char **cmd)
{
	int		status;
	pid_t	pid;
	int		i;

	while (tmp)
	{
		i = -1;
		if (tmp->type == E_FILE)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				dup2(open(tmp->str, O_RDONLY), STDIN_FILENO);
				while (path[++i])
					execve(path[i], cmd, NULL);
			}
			else
				waitpid(pid, &status, 0);
		}
		tmp = tmp->next;
	}
}

void	launch_cmd_without_file(char **path, char **options)
{
	pid_t	pid;
	int		status;
	int		i;

	i = -1;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		while (path[++i])
			execve(path[i], options, NULL);
	else
		waitpid(pid, &status, 0);
}

void	launch_cmd(t_env env)
{
	t_token	*tmp;
	char	**cmd_with_options;
	char	**path;

	tmp = env.token;
	cmd_with_options = tab_with_cmd_and_options(tmp);
	path = ft_create_path_for_execve(env.envp, cmd_with_options[0]);
	if (search_e_file_in_list(tmp) == 1)
		launch_cmd_if_file_in_list(tmp, path, cmd_with_options);
	else
		launch_cmd_without_file(path, cmd_with_options);
}
