/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_cmd_in_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:08:34 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/22 11:27:41 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Search the last sleep cmd in struct and return how many cmd we skip
 * @param cmd
 *
 * @return int
 */
//static int	ft_search_last_sleep_cmd_struc_cmd(t_cmd *cmd)
//{
//	int		i;
//	int		num;
//	t_cmd	*tmp;
//
//	i = 1;
//	num = 0;
//	tmp = cmd;
//	while (tmp)
//	{
//		if (ft_strncmp(tmp->name, "sleep", 5) == 0)
//			num = i;
//		i++;
//		tmp = tmp->next;
//	}
//	if (num == i)
//		return (0);
//	return (num);
//}

/**
 * Fonction who check if there is sleep cmd in struct
 * @param cmd 
 * 
 * @return int 
 */
//int	ft_check_if_sleep_cmd(t_cmd *cmd)
//{
//	t_cmd	*tmp;
//
//	tmp = cmd;
//	while (tmp)
//	{
//		if (!ft_strncmp(cmd->name, "sleep", 5))
//			return (1);
//		tmp = tmp->next;
//	}
//	return (0);
//}

/**
 * We search the last sleep in the struct, we make a loop and skip until the 
 * last sleep cmd element
 * @param cmd 
 * 
 * @return t_cmd* 
 */
//t_cmd	*ft_skip_until_last_sleep(t_cmd *cmd)
//{
//	int		i;
//	int		last_sleep_cmd_struc_cmd;
//
//	i = 0;
//	last_sleep_cmd_struc_cmd = ft_search_last_sleep_cmd_struc_cmd(cmd);
//	while (i < last_sleep_cmd_struc_cmd)
//	{
//		i++;
//		cmd = cmd->next;
//	}
//	return (cmd);
//}
