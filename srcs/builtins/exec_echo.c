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

/**
 * Print the token.
 *
 * @param t_token *tmp
 *
 * @return void
 */
static void	ft_print_token(t_token *list, int i, int has_n)
{
	while (list)
	{
		if (i > 1)
		{
			if (list->type == E_SPACE)
				printf(" ");
			else if (ft_strncmp(list->str, "-n", 3) == 0)
			{
				has_n = 1;
				if (!list->next)
					break ;
				list = list->next;
			}
			else
				printf("%s", list->str);
		}
		i++;
		list = list->next;
	}
	if (!has_n)
		printf("\n");
}

/**
 * Display the arguments passed to the echo command.
 *
 * @param t_token *list
 *
 * @return void
 */
void	ft_exec_echo(t_token *list)
{
	ft_print_token(list, 0, 0);
}
