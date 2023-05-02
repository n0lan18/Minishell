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

#include "../../minishell.h"

static void	check_all_option_n(t_token **tmp, t_param inc)
{
	while (*tmp && (ft_strncmp((*tmp)->str, "-n", 3) == 0
			|| (*tmp)->type == T_SPACE))
	{
		inc.i++;
		*tmp = (*tmp)->next;
	}
}

static void	print_token(t_token *tmp)
{
	if (tmp->type == T_SPACE)
		printf(" ");
	else
		printf("%s", tmp->str);
}

void	launch_echo(t_token *list)
{
	t_token	*tmp;
	int		has_n;
	t_param	inc;

	tmp = list;
	inc.i = 0;
	has_n = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->str, "-n", 3) == 0 && inc.i == 2)
		{
			has_n = 1;
			check_all_option_n(&tmp, inc);
			continue ;
		}
		else if (inc.i > 1)
		{
			print_token(tmp);
		}
		inc.i++;
		tmp = tmp->next;
	}
	if (!has_n)
		printf("\n");
}
