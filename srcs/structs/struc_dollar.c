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
 * Creates a linked list of t_dollar from the given tab dollars.
 * @param list_dollars
 * @param tab_dollars
 *
 * @return void
 */
void	ft_create_list_dollars(t_dollar **list_dollars, char **tab_dollars)
{
	int			i;
	t_dollar	*new;

	i = 0;
	while (tab_dollars[i])
	{
		new = malloc(sizeof(t_dollar));
		new->str = tab_dollars[i];
		new->next = NULL;
		ft_add_dollar_end(list_dollars, new);
		i++;
	}
}

/**
 * Adds a new envp at the end of the given list.
 * @param t_envp *list the current list of envp to add to
 * @param char *tab the string value of the new envp to add
 *
 * @return void
*/
void	ft_add_dollar_end(t_dollar **list_dollars, t_dollar *new)
{
	t_dollar	*current;

	if (!*list_dollars)
	{
		*list_dollars = new;
		return ;
	}
	current = *list_dollars;
	while (current->next)
		current = current->next;
	current->next = new;
}
