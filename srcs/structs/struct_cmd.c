/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:27:07 by synicole          #+#    #+#             */
/*   Updated: 2023/05/14 17:27:09 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*ft_new_cmd(t_token *token)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->name = token->str;
//	new->option = cmd->option;
//	new->fd_read = cmd->read;
//	new->fd_write = cmd->write;
	new->next = NULL;
	return (new);
}

/**
 * Adds a new command at the end of the given list.
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
