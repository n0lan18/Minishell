/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:09:51 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/25 10:10:05 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	launch_export(t_token *env, t_token *list)
{
	t_token *tmp;

	tmp = list;
	tmp = tmp->next;
	tmp = tmp->next;
	add_element(env, tmp->str);
}

int search_alpha_order(t_token *env, char *str)
{
	t_token	*tmp;
	int i;

	tmp = env;
	i = 0;
	while (tmp)
	{
		if ((tmp->str[0] >= 'a' && tmp->str[0] <= 'z') && (str[0] >= 'A' && str[0] <= 'Z'))
			tmp->str[0] -= 32;
		else if ((tmp->str[0] >= 'A' && tmp->str[0] <= 'Z') && (str[0] >= 'a' && str[0] <= 'z'))
			tmp->str[0] += 32;
		if (tmp->str[0] > str[0])
		{
			return (i - 1);
		}
		i++;
		tmp = tmp->next;
	}
	return (i);
}
