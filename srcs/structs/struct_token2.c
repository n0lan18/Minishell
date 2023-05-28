/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_token2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:50:47 by synicole          #+#    #+#             */
/*   Updated: 2023/05/28 22:50:49 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Add the previous token to each token of the list.
 *
 * @param current
 *
 * @return void
 */
void	ft_add_token_previous(t_token *token)
{
	while (token->next)
	{
		token->next->previous = token;
		token = token->next;
	}
	while (token->previous)
		token = token->previous;
}
