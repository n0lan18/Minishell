/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_built.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:48:35 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/27 12:42:05 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//int	check_if_built(t_token *list, t_token *env)
//{
//	t_token	*tmp;
//	int		num;
//	int		ret;
//
//	tmp = list;
//	num = check_if_built_bis(list);
//	if (num == 1)
//		return (0);
//	if (num < 0)
//		tmp = tmp->next;
//	ret = check_if_built_bis_bis_bis(tmp, env);
//	return (ret);
//}
//
//int	check_if_built_bis(t_token *list)
//{
//	int	num;
//
//	if ((list->str[0] == '"' && list->next == NULL) || \
//	(list->str[0] == '"' && list->next->next == NULL))
//		return (1);
//	if ((list->str[0] == 39 && list->next == NULL) || \
//	(list->str[0] == 39 && list->next->next == NULL))
//		return (1);
//	num = check_if_built_bis_bis(list);
//	return (num);
//}
//
//int	check_if_built_bis_bis(t_token *list)
//{
//	t_token	*tmp;
//	int		num;
//
//	num = 0;
//	tmp = list;
//	tmp = tmp->next;
//	if ((list->str[0] == '"' && tmp->str[0] == '"') || \
//	(list->str[0] == 39 && tmp->str[0] == 39))
//		num--;
//	return (num);
//}
//
//int	check_if_built_bis_bis_bis(t_token *tmp, t_token *env)
//{
//	if (ft_strncmp(tmp->str, "echo", 5) == 0)
//		launch_echo(tmp);
//	else if (ft_strncmp(tmp->str, "env", 4) == 0)
//		launch_env(env);
//	else if (ft_strncmp(tmp->str, "export", 7) == 0)
//		launch_export(env, tmp);
//	else if (ft_strncmp(tmp->str, "unset", 6) == 0)
//		launch_unset(env, tmp);
//	else if (ft_strncmp(tmp->str, "pwd", 4) == 0)
//		launch_pwd(env, tmp);
//	else if (ft_strncmp(tmp->str, "cd", 3) == 0)
//		launch_cd(env, tmp);
//	else if (ft_strncmp(tmp->str, "exit", 5) == 0)
//		ft_close();
//	else
//		return (0);
//	return (1);
//}
