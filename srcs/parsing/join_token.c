/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:38:23 by synicole          #+#    #+#             */
/*   Updated: 2023/05/06 22:38:24 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Merges two tokens.
 * @param current
 *
 * @return void
 */
static void	ft_merge_token(t_token *current)
{
	char	*tmp;

	tmp = ft_strjoin(current->str, current->next->str);
	free(current->str);
	current->str = tmp;
	current->next = current->next->next;
}

/**
 * Joins tokens that are not separated by a space.
 * @param env
 *
 * @return void
 */
void	ft_join_token_not_separate_by_space(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
		if (current->str[0] != ' ' && current->next
			&& current->next->str[0] != ' ')
			ft_merge_token(current);
		else
			current = current->next;
	}
}
