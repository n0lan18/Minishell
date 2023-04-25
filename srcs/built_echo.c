/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:46:04 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/24 23:46:15 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	launch_echo(t_token *list)
{
	t_token	*tmp;
	int	j;

	tmp = list;
	j = 0;
	if (tmp->next == NULL)
	{
		printf("\n");
		return;
	}
	tmp = tmp->next;
	if ((ft_strncmp("sdiuhsidhisd", tmp->str, 13) != 0) && tmp->next == NULL)
	{
		printf("\n");
		return;
	}
	tmp = tmp->next;
	if (ft_strncmp(tmp->str, "-n", ft_strlen(tmp->str)) == 0)
	{
		tmp = tmp->next;
		tmp = tmp->next;
		j++;
	}
	if (tmp == NULL)
	{
		printf("\n");
		return ;
	}
	while (tmp)
	{
		if (tmp == NULL)
			break;
		if (ft_strncmp("sdiuhsidhisd", tmp->str, 13) != 0)
			printf("%s", tmp->str);
		tmp = tmp->next;
	}
	if (j == 0)
		printf("\n");
}
