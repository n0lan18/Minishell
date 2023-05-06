/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:07:04 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/25 18:07:17 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//void	ft_run_unset(t_token *env, t_token *list)
//{
//	t_token	*tmp;
//	t_token	*temp;
//	t_token	*prev;
//	int		i;
//
//	tmp = env;
//	temp = list;
//	temp = temp->next;
//	temp = temp->next;
//	while (tmp)
//	{
//		i = compare_length_in_env(tmp->next->str);
//		if (ft_strncmp(tmp->next->str, temp->str, i) == 0)
//		{
//			prev = tmp;
//			tmp = tmp->next;
//			prev->next = tmp->next;
//			free(tmp);
//			return ;
//		}
//		prev = tmp;
//		tmp = tmp->next;
//	}
//}
