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
static void	ft_print_token(t_token *tmp)
{
	if (tmp->type == E_SPACE)
		printf(" ");
	else
		printf("%s", tmp->str);
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
	int		i;

	i = 0;
	while (list)
	{
		if (i > 1)
			ft_print_token(list);
		i++;
		list = list->next;
	}
	printf("\n");
}
