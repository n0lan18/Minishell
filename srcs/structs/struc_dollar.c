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
 * Creates a new t_dollar.
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
 * Adds a new dollar at the end of the given list.
 * @param t_dollar **list the current list of dollars to add to
 * @param t_dollar *new the new dollar to add
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
