/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:29:34 by synicole          #+#    #+#             */
/*   Updated: 2023/05/09 23:29:36 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Adds a new envp at the end of the given list.
 * @param t_envp *list the current list of envp to add to
 * @param char *tab the string value of the new envp to add
 *
 * @return t_envp* a pointer to the updated list of envp
*/
void	ft_add_dollar_end(t_dollar **lst, t_dollar *new)
{
	t_dollar	*current;

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
