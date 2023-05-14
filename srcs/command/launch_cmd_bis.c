/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cmd_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:25:41 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/12 11:28:36 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

///**
// * This fonction search in the list if the first element is a cmd or not
// * @param env
// *
// * @return int
// */
//int	check_if_cmd_first(t_env env)
//{
//	if (env.token->type == E_CMD)
//		return (1);
//	return (0);
//}
//
///**
// * Calcule how many size is the char **tab with E_CMD and E_SPACE and E_STRING
// * @param token
// *
// * @return int
// */
//int	size_of_char_for_cmd_options(t_token *token)
//{
//	t_token	*tmp;
//	int		i;
//
//	i = 0;
//	tmp = token;
//	while (tmp)
//	{
//		if (tmp->type == E_CMD || tmp->str[0] == '-' || tmp->type == E_SPACE)
//		{
//			if (tmp->type != E_SPACE)
//				i++;
//			tmp = tmp->next;
//		}
//		else
//			break ;
//	}
//	return (i);
//}
//
///**
// * This fonction create an array with cmd and options for execve
// * @param token
// *
// * @return char**
// */
//char	**tab_with_cmd_and_options(t_token *token)
//{
//	t_token	*tmp;
//	char	**tab;
//	int		i;
//
//	i = 0;
//	tab = malloc(sizeof(char *) * (size_of_char_for_cmd_options(token) + 1));
//	if (!tab)
//		return (NULL);
//	tmp = token;
//	while (i < size_of_char_for_cmd_options(token))
//	{
//		if (tmp->type == E_CMD || tmp->str[0] == '-')
//			tab[i++] = ft_strdup(tmp->str);
//		tmp = tmp->next;
//	}
//	tab[i] = NULL;
//	return (tab);
//}
//
///**
// * This fonction create the correct path who will be used in execve
// * @param env
// * @param cmd
// *
// * @return char**
// */
//char	**ft_create_path_for_execve(t_envp *env, char *cmd)
//{
//	t_envp	*tmp;
//	char	*env_path;
//	char	**envp;
//	int		i;
//
//	i = 0;
//	tmp = env;
//	while (tmp && ft_strncmp(tmp->name, "PATH", 4) != 0)
//		tmp = tmp->next;
//	env_path = ft_strdup(tmp->value);
//	envp = ft_split(env_path, ':');
//	while (envp[i])
//	{
//		envp[i] = join_all_path(envp[i], cmd, '/');
//		i++;
//	}
//	return (envp);
//}
//
///**
// * It search an E_FILE in the list and return 1 if it find it. It use in
// * launch_cmd fonction and separate the exec if there is a file in the list
// * or not
// * @param token
// *
// * @return int
// */
//int	search_e_file_in_list(t_token *token)
//{
//	t_token	*tmp;
//
//	tmp = token;
//	while (tmp)
//	{
//		if (tmp->type == E_FILE)
//			return (1);
//		tmp = tmp->next;
//	}
//	return (0);
//}
