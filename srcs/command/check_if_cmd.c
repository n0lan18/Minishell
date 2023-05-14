/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:52:50 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/11 16:41:46 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

///**
// * This fonction copy with malloc the value of env in a string
// * @param str
// * @return char*
// */
//static	char	*ft_strcpy_with_malloc(char *str)
//{
//	int		i;
//	char	*dst;
//
//	i = 0;
//	while (str[i])
//		i++;
//	dst = malloc(sizeof(char) * (i + 1));
//	if (!dst)
//		return (NULL);
//	i = 0;
//	while (str[i])
//	{
//		dst[i] = str[i];
//		i++;
//	}
//	dst[i] = '\0';
//	return (dst);
//}
//
///**
// * Join all path with slash and cmd. The perfect path is path/cmd
// * @param env
// * @param cmd
// * @param slash
// *
// * @return char*
// */
//char	*join_all_path(char *env, char *cmd, char slash)
//{
//	char	*join;
//	int		i;
//	int		j;
//
//	i = 0;
//	j = 0;
//	if (!env || !cmd)
//		return (NULL);
//	join = malloc(sizeof(char) * (ft_strlen(env) + ft_strlen(cmd) + slash + 1));
//	if (!join)
//		return (NULL);
//	while (env[i])
//		join[j++] = env[i++];
//	join[j] = slash;
//	j++;
//	i = 0;
//	while (cmd[i])
//		join[j++] = cmd[i++];
//	join[j] = '\0';
//	return (join);
//}
//
///**
// * Join all paths of envp with the cmd, it check if all path exist or not. If
// * 0 it is yes and free all var who were created
// * @param envp
// * @param tab
// *
// * @return int
// */
//static int	search_of_type_cmd_ext(char **envp, char *cmd)
//{
//	char	*temp;
//	int		i;
//
//	i = 0;
//	while (envp[i])
//	{
//		temp = join_all_path(envp[i], cmd, '/');
//		if (access(temp, F_OK) == 0)
//		{
//			free(temp);
//			free_double_tab(envp);
//			return (0);
//		}
//		free(temp);
//		i++;
//	}
//	free_double_tab(envp);
//	return (1);
//}
//
///**
// * Principal fonction of the file. It search the NAME PATH in the t_envp
// * struct, it copy the VALUE of PATH in envpi and split this VALUE every ':'
// * characters. At last it search in search_of_type_cmd_ext if this is an cmd
// * or not
// * @param env
// * @param tab
// *
// * @return int
// */
//int	search_of_type_cmd(t_envp *env, char *tab)
//{
//	t_envp	*tmp;
//	char	*envpi;
//	char	**envp;
//
//	tmp = env;
//	while (tmp && ft_strncmp(tmp->name, "PATH", 4) != 0)
//		tmp = tmp->next;
//	envpi = ft_strcpy_with_malloc(tmp->value);
//	envp = ft_split(envpi, ':');
//	return (search_of_type_cmd_ext(envp, tab));
//}
