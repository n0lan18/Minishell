/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:22:48 by synicole          #+#    #+#             */
/*   Updated: 2023/05/06 22:22:50 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Removes the quotes from the tokens.
 * @param env
 */
void	ft_trim_quote(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
		if (current->quote == E_SINGLE_QUOTE)
			current->str = ft_strtrim(current->str, "\'");
		else if (current->quote == E_DOUBLE_QUOTE)
			current->str = ft_strtrim(current->str, "\"");
		current = current->next;
	}
}
