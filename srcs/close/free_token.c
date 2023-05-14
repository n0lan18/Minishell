/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:01:41 by synicole          #+#    #+#             */
/*   Updated: 2023/05/14 19:01:42 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Frees the token list from the given environment.
 * @param t_token *token the token list to free
 *
 * @return void
*/
void	ft_free_token(t_env *env)
{
	t_token	*tmp;

	while (env->token)
	{
		tmp = env->token;
		env->token = env->token->next;
		free(tmp->str);
		free(tmp);
	}
}
