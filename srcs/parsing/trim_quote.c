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
	char	*trimmed;

	current = env->token;
	while (current)
	{
		if (current->quote == E_SINGLE_QUOTE)
		{
			trimmed = ft_strtrim(current->str, "\'");
			free(current->str);
			current->str = trimmed;
		}
		else if (current->quote == E_DOUBLE_QUOTE)
		{
			trimmed = ft_strtrim(current->str, "\"");
			free(current->str);
			current->str = trimmed;
		}
		current = current->next;
	}
}
