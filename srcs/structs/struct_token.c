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

t_token	*ft_new_token(char *str)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->str = str;
	new->type = ft_get_token_type(str);
	new->quote = ft_get_token_quote(str);
	new->next = NULL;
	return (new);
}

/**
 * Adds a new token at the end of the given list.
 * @param t_token *list the current list of tokens to add to
 * @param char *tab the string value of the new token to add
 *
 * @return t_token* a pointer to the updated list of tokens
*/
void	ft_add_token_end(t_token **lst, t_token *token)
{
	t_token	*current;

	current = *lst;
	if (!current)
		return ;
	else
	{
		while (current->next)
			current = current->next;
		current->next = token;
	}
}
