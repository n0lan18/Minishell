/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:46:04 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/26 19:23:40 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	launch_echo(t_token *list)
{
	t_token	*tmp;
	int		j;
	int		num;

	tmp = list;
	j = 0;
	num = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->str, "-n", 3) == 0 && j == 2)
			num++;
		if (j > 1 && tmp->str[0] == ' ')
			printf(" ");
		if ((j != 0 && ft_strncmp(tmp->str, "echo", 4) != 0) && \
		(j != 1 && ft_strncmp(tmp->str, " ", 1) != 0))
			tmp = launch_echo_bis(tmp, j);
		j++;
		tmp = tmp->next;
	}
	if (num == 0)
		printf("\n");
}

t_token	*launch_echo_bis(t_token *tmp, int j)
{
	if (tmp->str[0] == 39 && tmp->next != NULL)
	{
		tmp = tmp->next;
		while (tmp && tmp->str[0] != 39)
		{
			if (ft_strncmp(tmp->str, "💩", 14) != 0)
				printf("%s", tmp->str);
			tmp = tmp->next;
		}
	}
	else if (tmp->str[0] == '"' && tmp->next != NULL)
	{
		tmp = tmp->next;
		while (tmp && tmp->str[0] != '"')
		{
			if (ft_strncmp(tmp->str, "💩", 14) != 0)
				printf("%s", tmp->str);
			tmp = tmp->next;
		}
	}
	else if (!((ft_strncmp(tmp->str, "-n", 3) == 0 && j == 2) || \
	(ft_strncmp(tmp->str, "💩", 14) == 0)))
		printf("%s", tmp->str);
	return (tmp);
}
