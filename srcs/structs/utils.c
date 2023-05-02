/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:21:48 by synicole          #+#    #+#             */
/*   Updated: 2023/05/02 16:21:50 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Adds a new token at the end of the given list.
 * @param t_token *list the current list of tokens to add to
 * @param char *tab the string value of the new token to add
 *
 * @return t_token* a pointer to the updated list of tokens
*/
t_token	*ft_add_new_token(t_token *list, char *tab)
{
	t_token	*new_token;
	t_token	*current_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->str = tab;
	new_token->next = NULL;
	if (list == NULL)
		list = new_token;
	else
	{
		current_token = list;
		while (current_token->next)
			current_token = current_token->next;
		current_token->next = new_token;
	}
	return (list);
}
