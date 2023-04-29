/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:46:04 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/29 02:38:16 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	launch_echo(t_token *list, int check)
{
	t_token	*tmp;
	t_param	inc;

	tmp = list;
	inc.i = 0;
	inc.j = 0;
	inc.num = 0;
	if (check < 0)
		tmp = tmp->next;
	while (tmp)
	{
		if (ft_strncmp(tmp->str, "-n", 3) == 0 && inc.j == 2)
			inc.num++;
		if (inc.j > 1 && tmp->str[0] == ' ')
			printf(" ");
		if ((inc.j != 0 && ft_strncmp(tmp->str, "echo", 4) != 0) && \
		(inc.j != 1 && ft_strncmp(tmp->str, " ", 1) != 0))
			tmp = launch_echo_bis(tmp, inc.j, inc.i);
		inc.j++;
		tmp = tmp->next;
	}
	if (inc.num == 0)
		printf("\n");
}

t_token	*launch_echo_bis(t_token *tmp, int j, int i)
{
	i = 0;
	if (ft_strncmp(tmp->str, "-n", 3) == 0 && j == 2)
		return (tmp);
	while (i < search_str_in_str(tmp->str, "💩"))
		printf("%c", tmp->str[i++]);
//	else if (!((ft_strncmp(tmp->str, "-n", 3) == 0 && j == 2) || \
//	(ft_strncmp(tmp->str, "💩", 14) == 0)))
//		printf("%s", tmp->str);
	return (tmp);
}

int	search_str_in_str(char *first, char *second)
{
	t_param	inc;

	inc.i = 0;
	inc.j = 0;
	while (first[inc.i])
	{
		if (first[inc.i] == second[inc.j])
		{
			inc.num = inc.i;
			while (second[inc.j] && first[inc.i])
			{
				if (second[inc.j] != first[inc.i])
				{
					inc.j = 0;
					break ;
				}
				inc.i++;
				inc.j++;
			}
			if (second[inc.j] == '\0')
				return (ft_strlen(first));
		}
		inc.i++;
	}
	return (inc.num);
}
