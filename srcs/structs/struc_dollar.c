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
 * Creates a new t_doallar.
 * @param str
 *
 * @return t_dollar *new
 */
t_dollar	*ft_new_dollar(char *str)
{
	t_dollar	*new;

	new = malloc(sizeof(t_envp));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}

/**
 * Adds a new envp at the end of the given list.
 * @param t_envp *list the current list of envp to add to
 * @param char *tab the string value of the new envp to add
 *
 * @return void
*/
void	ft_add_dollar_end(t_dollar **lst, t_dollar *new)
{
	t_dollar	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}
