/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:29:29 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/27 11:22:16 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//t_token	*env_in_list(char **env, t_token *list)
//{
//	int		i;
//	t_token	*tmp;
//	char	*env_path;
//	char	cwd[1024];
//
//	i = -1;
//	tmp = list;
//	while (env[++i])
//	{
//		if (strncmp(env[i], "PATH=", 5) == 0)
//		{
//			getcwd(cwd, sizeof(cwd));
//			env_path = ft_strjoin(env[i], ft_strjoin(":", cwd));
//			tmp = add_new_element(tmp, env_path);
//		}
//		else
//			tmp = add_new_element(tmp, env[i]);
//	}
//	free(env_path);
//	return (tmp);
//}
//
//void	launch_env(t_token *env)
//{
//	t_token	*tmp;
//
//	tmp = env;
//	while (tmp)
//	{
//		printf("%s\n", tmp->str);
//		tmp = tmp->next;
//	}
//}
