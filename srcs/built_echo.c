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
	int	j;

	j = 0;
	if (list->next == NULL)
		return ;
	list = list->next;
	list = list->next;
	if (ft_strncmp(list->str, "-n", ft_strlen(list->str)) == 0)
	{
		list = list->next;
		list = list->next;
		j++;
	}
	while (list)
	{
		printf("%s", list->str);
		list = list->next;
	}
	if (j == 0)
		printf("\n");
}
