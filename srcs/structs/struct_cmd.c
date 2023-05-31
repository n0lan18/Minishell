/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:27:07 by synicole          #+#    #+#             */
/*   Updated: 2023/05/23 10:22:14 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Adds a new command at the end of the given list.
 *
 * @param t_cmd **list the current list of commands to add to
 * @param t_cmd *new the new command to add
 *
 * @return void
*/
void	ft_add_cmd_end(t_cmd **lst, t_cmd *new)
{
	t_cmd	*current;

	current = *lst;
	if (!current)
		return ;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
